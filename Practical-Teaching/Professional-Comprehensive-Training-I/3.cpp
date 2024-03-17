// Copyright (c) 2023 Xi Xu, All rights reserved.
// SPDX-License-Identifier: GPL-3.0-or-later

#include <bits/stdc++.h>

using namespace std;

// 同编程作业 1
double Evalue(const string &exp, int &pos) {
	char e = exp[pos];
	switch (e) {
	case '+':
		return Evalue(exp, ++pos) + Evalue(exp, ++pos);
	case '-':
		return Evalue(exp, ++pos) - Evalue(exp, ++pos);
	case '*':
		return Evalue(exp, ++pos) * Evalue(exp, ++pos);
	case '/':
		return Evalue(exp, ++pos) / Evalue(exp, ++pos);
	default:
		return e - '0';
	}
}

// 定义二叉树节点结构体
struct Node {
	int data;	 // 节点数据
	Node *left;	 // 左子节点指针
	Node *right; // 右子节点指针
	Node(int d, Node *l = nullptr, Node *r = nullptr) : data(d), left(l), right(r) {}
};

// 定义二叉树类型别名
using Tree = Node *;

// 根据表达式构建二叉树
Tree buildTree(const string &exp, int &pos) {
	char e = exp[pos]; // 获取当前字符
	switch (e) {
	case '+':
	case '-':
	case '*':
	case '/': {
		Tree t = new Node(e);			  // 创建一个新节点
		t->left = buildTree(exp, ++pos);  // 递归构建左子树
		t->right = buildTree(exp, ++pos); // 递归构建右子树
		return t;
	}
	default:
		return new Node(e - '0'); // 创建一个新节点，存储当前数字字符对应的数字
	}
}

// 判断节点是否为运算符
bool isOperator(const Tree t) {
	return t->data == '+' || t->data == '-' || t->data == '*' || t->data == '/';
}

// 判断两个运算符的优先级关系
bool lowerOrEqualPrecedence(const char op1, const char op2) {
	if (op1 == '+' || op1 == '-')
		return true;
	if (op1 == '*' || op1 == '/')
		return op2 == '*' || op2 == '/';
	return false;
}

// 中序遍历二叉树并输出表达式
void print(const Tree t) {
	if (t == nullptr)
		return;
	if (isOperator(t)) // 如果当前节点是运算符
	{
		bool leftParen = isOperator(t->left) && lowerOrEqualPrecedence(t->left->data, t->data);	   // 判断左子节点是否需要加括号
		bool rightParen = isOperator(t->right) && lowerOrEqualPrecedence(t->right->data, t->data); // 判断右子节点是否需要加括号
		if (leftParen)
			cout << "("; // 输出左括号
		print(t->left);	 // 递归输出左子树
		if (leftParen)
			cout << ")";	   // 输出右括号
		cout << (char)t->data; // 输出当前运算符
		if (rightParen)
			cout << "("; // 输出左括号
		print(t->right); // 递归输出右子树
		if (rightParen)
			cout << ")"; // 输出右括号
	}
	else
		cout << t->data; // 如果当前节点是数字，直接输出
}

int main() {
	string exp;
	cin >> exp;
	int pos = 0;
	cout << Evalue(exp, pos) << endl;
	pos = 0;
	Tree t = buildTree(exp, pos);
	print(t);
	cout << endl;
	return 0;
}