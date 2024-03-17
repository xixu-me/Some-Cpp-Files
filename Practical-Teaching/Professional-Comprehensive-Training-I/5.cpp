// Copyright (c) 2023 Xi Xu, All rights reserved.
// SPDX-License-Identifier: GPL-3.0-or-later

#include <bits/stdc++.h>

using namespace std;

// 定义记录结构体
struct Record {
	int id;		  // 学号
	string name;  // 姓名
	bool isMale;  // 性别
	double score; // 成绩
	Record(int id = 0, string name = "", bool isMale = true, double score = 0) : id(id), name(name), isMale(isMale), score(score) {}
};

// 定义比较函数
struct cmp {
	bool operator()(const Record &a, const Record &b) const {
		return a.id < b.id;
	}
};

int main() {
	// 定义记录集合
	set<Record, cmp> records;
	// 读取文件
	ifstream fin("E:\\OneDrive\\Code\\C++\\data.txt");
	string ignore;
	getline(fin, ignore);
	// 逐行读取文件
	while (!fin.eof()) {
		int id;
		string name, gender;
		bool isMale;
		double score;
		fin >> id >> name >> gender >> score;
		// 判断性别
		if (gender == "男")
			isMale = true;
		else
			isMale = false;
		// 添加记录
		records.insert(Record(id, name, isMale, score));
	}
	fin.close();
	// 定义列标志数组
	bool col[4];
	for (bool &b : col)
		b = false;
	double floorscore;
	char t;
	// 读取列标志和分数
	while (cin >> t, isdigit(t))
		col[t - '0' - 1] = true;
	cin >> floorscore;
	// 输出表头
	if (col[0])
		cout << "学号\t";
	if (col[1])
		cout << "姓名\t";
	if (col[2])
		cout << "性别\t";
	if (col[3])
		cout << "成绩" << endl;
	// 输出符合条件的记录
	for (const Record &r : records)
		if (r.score >= floorscore) {
			if (col[0])
				cout << r.id << "\t";
			if (col[1])
				cout << r.name << "\t";
			if (col[2]) {
				if (r.isMale)
					cout << "男\t";
				else
					cout << "女\t";
			}
			if (col[3])
				cout << r.score;
			cout << endl;
		}
	return 0;
}