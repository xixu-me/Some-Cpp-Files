// Copyright (c) 2023 Xi Xu
// SPDX-License-Identifier: GPL-3.0-or-later

#include <bits/stdc++.h>

using namespace std;

class Graph // 定义 Graph 类
{
private:
	int n, e;  // n 表示节点数，e 表示边数
	int **adj; // 邻接矩阵

public:
	Graph(istream &in); // 构造函数
	int cnt2();			// 计算邻接矩阵的平方中边的数量
};

Graph::Graph(istream &in) // 构造函数实现
{
	in >> n >> e;				   // 读入节点数和边数
	adj = new int *[n];			   // 动态分配邻接矩阵内存
	for (size_t i = 0; i < n; i++) // 初始化邻接矩阵
	{
		adj[i] = new int[n];
		for (size_t j = 0; j < n; j++)
			adj[i][j] = 0;
	}
	for (size_t i = 0; i < e; i++) // 读入边
	{
		int u, v;
		in >> u >> v;
		adj[u - 1][v - 1]++; // 在邻接矩阵中标记边
	}
}

int Graph::cnt2() // 计算长度为 2 的通路数
{
	int adj2[n][n];				   // 定义邻接矩阵的平方
	memset(adj2, 0, sizeof(adj2)); // 将邻接矩阵的平方初始化为 0
	for (int i = 0; i < n; i++)	   // 计算邻接矩阵的平方
		for (int j = 0; j < n; j++)
			for (int k = 0; k < n; k++)
				adj2[i][j] += adj[i][k] * adj[k][j];
	int cnt = 0;				   // 定义边的数量
	for (size_t i = 0; i < n; i++) // 统计边的数量
		for (size_t j = 0; j < n; j++)
			cnt += adj2[i][j];
	return cnt; // 返回边的数量
}

int main() {
	ifstream fin("E:\\OneDrive\\Code\\C++\\graph.txt"); // 打开文件
	Graph g(fin);										// 创建 Graph 对象 g
	cout << g.cnt2() << endl;							// 输出 g 中的长度为 2 的通路数
	return 0;
}