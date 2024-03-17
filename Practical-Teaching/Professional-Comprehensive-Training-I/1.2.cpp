// Copyright (c) 2023 Xi Xu
// SPDX-License-Identifier: GPL-3.0-or-later

#include <bits/stdc++.h>

using namespace std;

// 定义节点结构体
struct Node {
	char operato;	// 运算符
	double operand; // 操作数
	Node *left;		// 左子树
	Node *right;	// 右子树
	Node(char o = 0, double d = 0, Node *l = nullptr, Node *r = nullptr) : operato(o), operand(d), left(l), right(r) {}
};

// 定义树类型
using Tree = Node *;

// 递归构建表达式树
Tree buildTree(stringstream &ss) {
	string e;
	ss >> e;
	// 如果是加法
	if (e == "add") {
		Tree t = new Node('+');
		t->left = buildTree(ss);
		t->right = buildTree(ss);
		return t;
	}
	// 如果是减法
	else if (e == "sub") {
		Tree t = new Node('-');
		t->left = buildTree(ss);
		t->right = buildTree(ss);
		return t;
	}
	// 如果是乘法
	else if (e == "muti") {
		Tree t = new Node('*');
		t->left = buildTree(ss);
		t->right = buildTree(ss);
		return t;
	}
	// 如果是除法
	else if (e == "div") {
		Tree t = new Node('/');
		t->left = buildTree(ss);
		t->right = buildTree(ss);
		return t;
	}
	// 如果是取负
	else if (e == "neg") {
		double temp;
		ss >> temp;
		return new Node(0, -temp);
	}
	// 如果是平方
	else if (e == "doubleMe") {
		Tree t = new Node('^');
		double temp;
		ss >> temp;
		t->left = new Node(0, temp);
		t->right = new Node(0, 2);
		return t;
	}
	// 如果是数字
	else
		return new Node(0, atof(e.c_str()));
}

// 判断节点是否为运算符
bool isOperator(const Tree t) {
	return t->operato != 0;
}

// 定义运算符优先级
map<char, int> priority{ { '+', 1 }, { '-', 1 }, { '*', 2 }, { '/', 2 }, { '^', 3 } };

// 判断运算符优先级是否小于等于另一个运算符
bool lowerOrEqualPrecedence(const char op1, const char op2) {
	return priority[op1] <= priority[op2];
}

// 输出表达式树
void print(ostream &out, const Tree t = nullptr) {
	if (t == nullptr)
		return;
	if (isOperator(t)) {
		bool leftParen = isOperator(t->left) && lowerOrEqualPrecedence(t->left->operato, t->operato);
		bool rightParen = isOperator(t->right) && lowerOrEqualPrecedence(t->right->operato, t->operato);
		if (leftParen)
			out << "(";
		print(out, t->left);
		if (leftParen)
			out << ")";
		out << ' ' << t->operato << ' ';
		if (rightParen)
			out << "(";
		print(out, t->right);
		if (rightParen)
			out << ")";
	}
	else
		out << t->operand;
}

// 计算表达式树的值
double evaluate(const Tree t) {
	if (t == nullptr)
		return 0;
	if (isOperator(t)) {
		double left = evaluate(t->left);
		double right = evaluate(t->right);
		switch (t->operato) {
		case '+':
			return left + right;
		case '-':
			return left - right;
		case '*':
			return left * right;
		case '/':
			return left / right;
		case '^':
			return pow(left, right);
		}
	}
	return t->operand;
}

int main() {
	// 从文件中读取表达式
	ifstream fin("E:\\OneDrive\\Code\\C++\\Professional-Comprehensive-Training-I\\question.txt");
	// 将计算结果写入文件
	ofstream fout("E:\\OneDrive\\Code\\C++\\Professional-Comprehensive-Training-I\\answer.txt");
	string line;
	while (getline(fin, line)) {
		string temp = line;
		// 将括号和逗号替换为空格
		for (char &c : temp)
			if (c == '(' || c == ')' || c == ',')
				c = ' ';
		// 将表达式转换为流并构建表达式树
		stringstream ss(temp);
		Tree t = buildTree(ss);
		// 输出表达式和计算结果
		print(fout, t);
		fout << " = " << evaluate(t);
		fout << endl;
	}
	// 关闭文件
	fin.close();
	fout.close();
	return 0;
}
