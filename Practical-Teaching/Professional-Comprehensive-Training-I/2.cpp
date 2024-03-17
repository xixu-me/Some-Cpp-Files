// Copyright (c) 2023 Xi Xu, All rights reserved.
// SPDX-License-Identifier: GPL-3.0-or-later

#include <bits/stdc++.h>

using namespace std;

int main() {
	ifstream fin("a.txt");	// 打开文件“a.txt”以读取模式
	ofstream fout("b.txt"); // 打开文件“b.txt”以写入模式
	string line;
	while (getline(fin, line)) // 从文件“a.txt”中读取一行到 line 中
	{
		for (char &c : line)					  // 遍历 line 中的每个字符
			if (c == '(' || c == ')' || c == ',') // 如果字符是“(”或“)”或“,”
				c = ' ';						  // 将字符替换为空格
		fout << line << endl;					  // 将 line 写入文件“b.txt”中并换行
	}
	fin.close();  // 关闭文件“a.txt”
	fout.close(); // 关闭文件“b.txt”
	return 0;
}