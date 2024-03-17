// Copyright (c) 2023 Xi Xu, All rights reserved.
// SPDX-License-Identifier: GPL-3.0-or-later

#include <bits/stdc++.h>

using namespace std;

// 递归计算表达式的值
double Evalue(const string &exp, int &pos) {
	char e = exp[pos]; // 取出当前位置的字符
	switch (e)		   // 根据字符类型进行不同的计算
	{
	case '+':
		return Evalue(exp, ++pos) + Evalue(exp, ++pos); // 如果是加号，则计算左右两边表达式的值之和
	case '-':
		return Evalue(exp, ++pos) - Evalue(exp, ++pos); // 如果是减号，则计算左右两边表达式的值之差
	case '*':
		return Evalue(exp, ++pos) * Evalue(exp, ++pos); // 如果是乘号，则计算左右两边表达式的值之积
	case '/':
		return Evalue(exp, ++pos) / Evalue(exp, ++pos); // 如果是除号，则计算左右两边表达式的值之商
	default:
		return e - '0'; // 如果是数字，则返回该数字的值
	}
}

int main() {
	string exp;
	cin >> exp;
	int pos = 0;
	cout << Evalue(exp, pos) << endl;
	return 0;
}