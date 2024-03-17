// Copyright (c) 2023 徐丞烨，王凯钦，宋析峰，杨崇新
// SPDX-License-Identifier: GPL-3.0-or-later

#include <bits/stdc++.h>

using namespace std;

class Graph {
private:
	int n;	   // 图的顶点数
	int **adj; // 邻接矩阵

public:
	Graph(istream &in); // 构造函数，从输入流in中读取邻接矩阵
	~Graph();			// 析构函数，释放邻接矩阵的内存
	void floyd() const; // Floyd算法，计算任意两点之间的最短路径
};

Graph::Graph(istream &in) {
	in >> n;			// 读取顶点数
	adj = new int *[n]; // 动态分配二维数组
	for (size_t i = 0; i < n; i++) {
		adj[i] = new int[n];
		for (size_t j = 0; j < n; j++)
			in >> adj[i][j]; // 读取邻接矩阵
	}
}

Graph::~Graph() {
	for (size_t i = 0; i < n; i++)
		delete[] adj[i]; // 释放每一行的内存
	delete[] adj;		 // 释放二维数组的内存
}

void Graph::floyd() const {
	int dist[n][n]; // 存储任意两点之间的最短距离
	int path[n][n]; // 存储任意两点之间的最短路径
	for (size_t i = 0; i < n; i++)
		for (size_t j = 0; j < n; j++) {
			dist[i][j] = adj[i][j]; // 初始化最短距离
			path[i][j] = j;			// 初始化最短路径
		}
	for (size_t k = 0; k < n; k++)
		for (size_t i = 0; i < n; i++)
			for (size_t j = 0; j < n; j++)
				if (dist[i][k] + dist[k][j] < dist[i][j]) // 如果经过k点的路径更短
				{
					dist[i][j] = dist[i][k] + dist[k][j]; // 更新最短距离
					path[i][j] = path[i][k];			  // 更新最短路径
				}
	for (size_t i = 0; i < n; i++) {
		cout << "From " << i + 1 << ":" << endl; // 输出起点
		for (size_t j = 0; j < n; j++) {
			if (i == j)
				continue;
			cout << "To " << j + 1 << ": ";
			cout << i + 1 << " "; // 输出起点
			int k = path[i][j];
			while (k != j) // 输出路径上的中间点
			{
				cout << k + 1 << " ";
				k = path[k][j];
			}
			cout << j + 1 << endl; // 输出终点
		}
		cout << endl;
	}
}

int main() {
	// 打开输入文件
	ifstream fin("adj.txt");
	// 创建图
	Graph g(fin);
	// 关闭输入文件
	fin.close();
	// 计算任意两点之间的最短路径
	g.floyd();
	return 0;
}