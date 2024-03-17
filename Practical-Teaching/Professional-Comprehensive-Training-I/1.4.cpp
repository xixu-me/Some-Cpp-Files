// Copyright (c) 2023 Xi Xu, All rights reserved.
// SPDX-License-Identifier: GPL-3.0-or-later

#include <bits/stdc++.h>

using namespace std;

// 定义一个结构体，表示一条记录
struct Record {
	int id;		 // 记录的id
	string name; // 记录的名字
	bool isMale; // 记录的性别
	double data; // 记录的数据
	Record(int id = 0, string name = "", bool isMale = true, double data = 0) : id(id), name(name), isMale(isMale), data(data) {}
};

// 定义一个比较函数对象，用于将记录按照id从小到大排序
struct cmp {
	bool operator()(const Record &a, const Record &b) const {
		return a.id < b.id;
	}
};

// 从输入流in中读取记录，将记录插入到set中并返回
set<Record, cmp> table(istream &in) {
	set<Record, cmp> table; // 定义一个set，用于存储记录
	while (!in.eof())		// 循环读取输入流中的记录
	{
		int id;
		string name, gender;
		bool isMale;
		double data;
		in >> id >> name >> gender >> data; // 从输入流中读取记录的各个字段
		if (gender == "male")				// 判断记录的性别
			isMale = true;
		else
			isMale = false;
		table.insert(Record(id, name, isMale, data)); // 将记录插入到set中
	}
	return table; // 返回set
}

int main() {
	string sql;
	while (getline(cin, sql)) // 从标准输入读取一行 SQL 语句
	{
		ifstream sfin("stu.txt"), efin("employee.txt"); // 打开两个文件
		if (!sfin.is_open() || !efin.is_open())			// 如果文件打开失败
		{
			cout << "File not found!" << endl; // 输出错误信息
			return 0;						   // 退出程序
		}
		set<Record, cmp> stu = table(sfin), employee = table(efin); // 从文件中读取数据并存储到 set 容器中
		sfin.close(), efin.close();									// 关闭文件
		if (sql == "EXIT")											// 如果输入的 SQL 语句为 EXIT
			break;													// 退出循环
		stringstream ss(sql);										// 将 SQL 语句转换为 stringstream 流
		string tmp;
		bool col[4], isStu, isMale;
		double limits;
		ss >> tmp;
		if (tmp != "SELECT") // 如果 SQL 语句不是 SELECT
		{
			cout << "Invalid SQL!" << endl; // 输出错误信息
			continue;						// 继续下一次循环
		}
		ss >> tmp;
		if (tmp == "*") // 如果 SQL 语句为 SELECT *
		{
			for (bool &b : col)
				b = true; // 将 col 数组中的所有元素都设置为 true
			ss >> tmp;
		}
		else {
			bool conti = false;
			for (bool &b : col)
				b = false; // 将 col 数组中的所有元素都设置为 false
			do {
				if (tmp == "ID" || tmp == "ID,")
					col[0] = true; // 如果 SQL 语句中包含 ID，将 col[0] 设置为 true
				else if (tmp == "Name" || tmp == "Name,")
					col[1] = true; // 如果 SQL 语句中包含 Name，将 col[1] 设置为 true
				else if (tmp == "Gender" || tmp == "Gender,")
					col[2] = true; // 如果 SQL 语句中包含 Gender，将 col[2] 设置为 true
				else if (tmp == "Score" || tmp == "Score," || tmp == "Salary" || tmp == "Salary,")
					col[3] = true; // 如果 SQL 语句中包含 Score 或 Salary，将 col[3] 设置为 true
				else {
					if (tmp != "FROM") {
						cout << "The type of data does not exist!" << endl; // 输出错误信息
						conti = true;										// 设置 conti 为 true
					}
					break;
				}
			} while (ss >> tmp);
			if (conti)
				continue; // 继续下一次循环
		}
		if (tmp != "FROM") // 如果 SQL 语句不是 FROM
		{
			cout << "Invalid SQL!" << endl; // 输出错误信息
			continue;						// 继续下一次循环
		}
		else {
			ss >> tmp;
			if (tmp != "stu" && tmp != "employee") // 如果 SQL 语句中不包含 stu 或 employee
			{
				cout << "The table does not exist!" << endl; // 输出错误信息
				continue;									 // 继续下一次循环
			}
			else {
				isStu = tmp == "stu"; // 如果 SQL 语句中包含 stu，将 isStu 设置为 true，否则设置为 false
			}
		}
		if (ss >> tmp) // 如果 SQL 语句中包含 WHERE
		{
			if (tmp != "WHERE") // 如果 SQL 语句中 WHERE 后面不是条件
			{
				cout << "Invalid SQL!" << endl; // 输出错误信息
				continue;						// 继续下一次循环
			}
			else {
				bool conti = false;
				while (ss >> tmp) {
					if (tmp == "Score" || tmp == "Salary") // 如果 SQL 语句中包含 Score 或 Salary
					{
						ss >> tmp;
						if (tmp == ">=") {
							ss >> limits;
							if (isStu) {
								for (auto it = stu.begin(); it != stu.end();) {
									if (it->data < limits)
										it = stu.erase(it); // 如果数据小于 limits，将该数据从 set 容器中删除
									else
										++it;
								}
							}
							else {
								for (auto it = employee.begin(); it != employee.end();) {
									if (it->data < limits)
										it = employee.erase(it); // 如果数据小于 limits，将该数据从 set 容器中删除
									else
										++it;
								}
							}
						}
						else if (tmp == "<=") {
							ss >> limits;
							if (isStu) {
								for (auto it = stu.begin(); it != stu.end();) {
									if (it->data > limits)
										it = stu.erase(it); // 如果数据大于 limits，将该数据从 set 容器中删除
									else
										++it;
								}
							}
							else {
								for (auto it = employee.begin(); it != employee.end();) {
									if (it->data > limits)
										it = employee.erase(it); // 如果数据大于 limits，将该数据从 set 容器中删除
									else
										++it;
								}
							}
						}
						else if (tmp == "=") {
							ss >> limits;
							if (isStu) {
								for (auto it = stu.begin(); it != stu.end();) {
									if (it->data != limits)
										it = stu.erase(it); // 如果数据不等于 limits，将该数据从 set 容器中删除
									else
										++it;
								}
							}
							else {
								for (auto it = employee.begin(); it != employee.end();) {
									if (it->data != limits)
										it = employee.erase(it); // 如果数据不等于 limits，将该数据从 set 容器中删除
									else
										++it;
								}
							}
						}
						else if (tmp == "<") {
							ss >> limits;
							if (isStu) {
								for (auto it = stu.begin(); it != stu.end();) {
									if (it->data >= limits)
										it = stu.erase(it); // 如果数据大于等于 limits，将该数据从 set 容器中删除
									else
										++it;
								}
							}
							else {
								for (auto it = employee.begin(); it != employee.end();) {
									if (it->data >= limits)
										it = employee.erase(it); // 如果数据大于等于 limits，将该数据从 set 容器中删除
									else
										++it;
								}
							}
						}
						else if (tmp == ">") {
							ss >> limits;
							if (isStu) {
								for (auto it = stu.begin(); it != stu.end();) {
									if (it->data <= limits)
										it = stu.erase(it); // 如果数据小于等于 limits，将该数据从 set 容器中删除
									else
										++it;
								}
							}
							else {
								for (auto it = employee.begin(); it != employee.end();) {
									if (it->data <= limits)
										it = employee.erase(it); // 如果数据小于等于 limits，将该数据从 set 容器中删除
									else
										++it;
								}
							}
						}
						else {
							cout << "Invalid SQL!" << endl; // 输出错误信息
							conti = true;					// 设置 conti 为 true
							continue;
						}
					}
					else if (tmp == "Gender") // 如果 SQL 语句中包含 Gender
					{
						ss >> tmp;
						if (tmp != "=") {
							cout << "Invalid SQL!" << endl; // 输出错误信息
							conti = true;					// 设置 conti 为 true
							continue;
						}
						ss >> tmp;
						if (tmp == "male")
							isMale = true; // 如果 SQL 语句中包含 male，将 isMale 设置为 true
						else if (tmp == "female")
							isMale = false; // 如果 SQL 语句中包含 female，将 isMale 设置为 false
						else {
							cout << "Invalid SQL!" << endl; // 输出错误信息
							conti = true;					// 设置 conti 为 true
							continue;
						}
						if (isStu) {
							for (auto it = stu.begin(); it != stu.end();) {
								if (it->isMale != isMale)
									it = stu.erase(it); // 如果数据的性别与 isMale 不同，将该数据从 set 容器中删除
								else
									++it;
							}
						}
						else {
							for (auto it = employee.begin(); it != employee.end();) {
								if (it->isMale != isMale)
									it = employee.erase(it); // 如果数据的性别与 isMale 不同，将该数据从 set 容器中删除
								else
									++it;
							}
						}
					}
					else if (tmp == "AND")
						continue; // 如果 SQL 语句中包含 AND，继续下一次循环
					else {
						cout << "Invalid SQL!" << endl; // 输出错误信息
						conti = true;					// 设置 conti 为 true
						continue;
					}
				}
				if (conti)
					continue; // 继续下一次循环
			}
		}
		if (isStu) // 如果 SQL 语句中包含 stu
		{
			if (col[0])
				cout << "ID ";
			if (col[1])
				cout << "Name ";
			if (col[2])
				cout << "Gender ";
			if (col[3])
				cout << "Score ";
			cout << endl;
			for (auto it = stu.begin(); it != stu.end(); ++it) {
				if (col[0])
					cout << it->id << " ";
				if (col[1])
					cout << it->name << " ";
				if (col[2])
					cout << (it->isMale ? "male" : "female") << " ";
				if (col[3])
					cout << it->data << " ";
				cout << endl;
			}
		}
		else // 如果 SQL 语句中包含 employee
		{
			if (col[0])
				cout << "ID ";
			if (col[1])
				cout << "Name ";
			if (col[2])
				cout << "Gender ";
			if (col[3])
				cout << "Salary ";
			cout << endl;
			for (auto it = employee.begin(); it != employee.end(); ++it) {
				if (col[0])
					cout << it->id << " ";
				if (col[1])
					cout << it->name << " ";
				if (col[2])
					cout << (it->isMale ? "male" : "female") << " ";
				if (col[3])
					cout << it->data << " ";
				cout << endl;
			}
		}
	}
}