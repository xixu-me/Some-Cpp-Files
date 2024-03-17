// Copyright (c) 2023 Xi Xu, All rights reserved.
// SPDX-License-Identifier: GPL-3.0-or-later

#include <bits/stdc++.h>

using namespace std;

// 定义一个函数，用于计算表达式的值
double Evalue(stringstream &exp) {
	string e;
	exp >> e;
	// 如果是加法
	if (e == "add")
		// 递归计算左右两个操作数的值并相加
		return Evalue(exp) + Evalue(exp);
	// 如果是减法
	else if (e == "sub")
		// 递归计算左右两个操作数的值并相减
		return Evalue(exp) - Evalue(exp);
	// 如果是乘法
	else if (e == "muti")
		// 递归计算左右两个操作数的值并相乘
		return Evalue(exp) * Evalue(exp);
	// 如果是除法
	else if (e == "div")
		// 递归计算左右两个操作数的值并相除
		return Evalue(exp) / Evalue(exp);
	// 如果是取负
	else if (e == "neg") {
		double temp;
		exp >> temp;
		// 取负并返回
		return -temp;
	}
	// 如果是平方
	else if (e == "doubleMe") {
		double temp;
		exp >> temp;
		// 平方并返回
		return temp * temp;
	}
	// 如果是数字
	else
		// 直接返回数字
		return atof(e.c_str());
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
		// 将表达式转换为流并计算结果
		stringstream exp(temp);
		fout << line << " = " << Evalue(exp) << endl;
	}
	// 关闭文件
	fin.close();
	fout.close();
	return 0;
}
