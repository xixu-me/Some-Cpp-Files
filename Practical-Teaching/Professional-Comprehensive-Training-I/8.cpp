// Copyright (c) 2023 Xi Xu, All rights reserved.
// SPDX-License-Identifier: GPL-3.0-or-later

#include <bits/stdc++.h>

using namespace std;

class Graph // 完全图类
{
private:
	int n;	 // 节点数
	int **w; // 每条边的权值

public:
	Graph(istream &in); // 构造函数，从输入流中读取图的信息
	~Graph();			// 析构函数，释放内存
	int tsp();			// 求解 TSP 问题
};

Graph::Graph(istream &in) {
	in >> n; // 读取节点数
	w = new int *[n];
	for (size_t i = 0; i < n; i++) {
		w[i] = new int[n];
	}
	for (size_t i = 0; i < n; i++) // 读取每条边的权值
	{
		w[i][i] = 0; // 对角线上的元素为 0
		for (int j = i + 1; j < n; j++) {
			in >> w[i][j];	   // 读取上三角元素
			w[j][i] = w[i][j]; // 下三角元素与上三角元素相等
		}
	}
}

Graph::~Graph() {
	for (size_t i = 0; i < n; i++)
		delete[] w[i];
	delete[] w;
}

int Graph::tsp() // Graph 类的求解 TSP 问题的函数
{
	int p[n]; // 存储节点的排列
	for (int i = 0; i < n; i++)
		p[i] = i;	   // 初始排列为 0, 1, ..., n-1
	int min = INT_MAX; // 存储最小路径长度
	do				   // 枚举所有可能的排列
	{
		int sum = 0; // 计算当前排列的路径长度
		for (int i = 0; i < n - 1; i++)
			sum += w[p[i]][p[i + 1]];
		sum += w[p[n - 1]][p[0]];
		if (sum < min) // 更新最小路径长度
			min = sum;
	} while (next_permutation(p, p + n)); // STL 中的排列生成函数
	return min;							  // 返回最小路径长度
}

int main() {
	ifstream fin("graph.txt"); // 打开输入文件
	Graph g(fin);			   // 创建 Graph 类的对象
	fin.close();			   // 关闭输入文件
	cout << g.tsp() << endl;   // 求解 TSP 问题
	return 0;
}