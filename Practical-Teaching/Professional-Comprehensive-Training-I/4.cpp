// Copyright (c) 2023 Xi Xu
// SPDX-License-Identifier: GPL-3.0-or-later

#include <bits/stdc++.h>

using namespace std;

map<char, int> priority{ { '+', 1 }, { '-', 1 }, { '*', 2 }, { '/', 2 } };

double Evalue(const string &s) {
	stack<double> num; // 存储数字的栈
	stack<char> op;	   // 存储运算符的栈
	int i = 0;
	while (i < s.size()) {
		if (s[i] == ' ') // 如果是空格则跳过
		{
			i++;
			continue;
		}
		if (isdigit(s[i])) // 如果是数字则将其转换为 double 类型并压入数字栈
		{
			double temp = 0;
			while (i < s.size() && isdigit(s[i])) {
				temp = temp * 10 + s[i] - '0';
				i++;
			}
			num.push(temp);
		}
		else if (s[i] == '(') // 如果是左括号则将其压入运算符栈
		{
			op.push(s[i]);
			i++;
		}
		else if (s[i] == ')') // 如果是右括号则进行运算
		{
			while (op.top() != '(') // 直到遇到左括号为止
			{
				double b = num.top(); // 取出数字栈的栈顶元素
				num.pop();			  // 弹出数字栈的栈顶元素
				double a = num.top(); // 取出数字栈的栈顶元素
				num.pop();			  // 弹出数字栈的栈顶元素
				char c = op.top();	  // 取出运算符栈的栈顶元素
				op.pop();			  // 弹出运算符栈的栈顶元素
				if (c == '+')		  // 进行加法运算
					num.push(a + b);
				else if (c == '-') // 进行减法运算
					num.push(a - b);
				else if (c == '*') // 进行乘法运算
					num.push(a * b);
				else if (c == '/') // 进行除法运算
					num.push(a / b);
			}
			op.pop(); // 弹出左括号
			i++;
		}
		else // 如果是运算符则进行运算
		{
			while (!op.empty() && op.top() != '(' && priority[op.top()] >= priority[s[i]]) // 如果运算符栈不为空且栈顶元素不是左括号且当前运算符的优先级小于等于栈顶运算符的优先级
			{
				double b = num.top(); // 取出数字栈的栈顶元素
				num.pop();			  // 弹出数字栈的栈顶元素
				double a = num.top(); // 取出数字栈的栈顶元素
				num.pop();			  // 弹出数字栈的栈顶元素
				char c = op.top();	  // 取出运算符栈的栈顶元素
				op.pop();			  // 弹出运算符栈的栈顶元素
				if (c == '+')		  // 进行加法运算
					num.push(a + b);
				else if (c == '-') // 进行减法运算
					num.push(a - b);
				else if (c == '*') // 进行乘法运算
					num.push(a * b);
				else if (c == '/') // 进行除法运算
					num.push(a / b);
			}
			op.push(s[i]); // 将当前运算符压入运算符栈
			i++;
		}
	}
	while (!op.empty()) // 如果运算符栈不为空则进行运算
	{
		double b = num.top(); // 取出数字栈的栈顶元素
		num.pop();			  // 弹出数字栈的栈顶元素
		double a = num.top(); // 取出数字栈的栈顶元素
		num.pop();			  // 弹出数字栈的栈顶元素
		char c = op.top();	  // 取出运算符栈的栈顶元素
		op.pop();			  // 弹出运算符栈的栈顶元素
		if (c == '+')		  // 进行加法运算
			num.push(a + b);
		else if (c == '-') // 进行减法运算
			num.push(a - b);
		else if (c == '*') // 进行乘法运算
			num.push(a * b);
		else if (c == '/') // 进行除法运算
			num.push(a / b);
	}
	return num.top(); // 返回数字栈的栈顶元素
}

int main() {
	string s;
	getline(cin, s);
	cout << Evalue(s) << endl;
	return 0;
}