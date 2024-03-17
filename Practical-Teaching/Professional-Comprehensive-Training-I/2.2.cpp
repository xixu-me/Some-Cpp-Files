// Copyright (c) 2023 徐丞烨，王凯钦，宋析峰，杨崇新
// SPDX-License-Identifier: GPL-3.0-or-later

#include <bits/stdc++.h>

using namespace std;

class Graph {
private:
	int n;	   // 图的顶点数
	int **adj; // 邻接矩阵

public:
	Graph(istream &in);												   // 构造函数，从输入流in中读取邻接矩阵
	~Graph();														   // 析构函数，释放邻接矩阵的内存
	int tsp();														   // TSP 算法，计算最短哈密顿回路
	void tsp_backtrack(int k, int *path, int *visited, int &min_path); // 回溯法
	int path_len(int *path, int k);									   // 计算路径长度
};

Graph::Graph(istream &in) {
	in >> n;			// 读取顶点数
	adj = new int *[n]; // 动态分配二维数组
	for (size_t i = 0; i < n; i++) {
		adj[i] = new int[n];
	}
	for (size_t i = 0; i < n; i++) {
		adj[i][i] = 0; // 对角线上的元素为0
		for (int j = i + 1; j < n; j++) {
			in >> adj[i][j];	   // 读取邻接矩阵
			adj[j][i] = adj[i][j]; // 邻接矩阵是对称矩阵
		}
	}
}

Graph::~Graph() {
	for (size_t i = 0; i < n; ++i)
		delete[] adj[i]; // 释放每一行的内存
	delete[] adj;		 // 释放二维数组的内存
}

int Graph::tsp() {
	int *path = new int[n];	   // 存储当前的路径
	int *visited = new int[n]; // 存储已经访问过的顶点
	int min_path = INT_MAX;	   // 存储最短路径长度

	// 初始化
	for (int i = 0; i < n; i++) {
		visited[i] = 0;
	}
	visited[0] = 1;
	path[0] = 0;

	// 回溯
	tsp_backtrack(1, path, visited, min_path);

	// 释放内存
	delete[] path;
	delete[] visited;

	return min_path;
}

void Graph::tsp_backtrack(int k, int *path, int *visited, int &min_path) {
	if (k == n) // 所有的顶点都已经遍历完了
	{
		int path_len = 0;
		for (int i = 0; i < n - 1; i++) {
			path_len += adj[path[i]][path[i + 1]];
		}
		path_len += adj[path[n - 1]][0]; // 回到起点
		if (path_len < min_path) {
			min_path = path_len;
		}
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			path[k] = i;
			visited[i] = 1;
			if (path_len(path, k) < min_path) // 剪枝
			{
				tsp_backtrack(k + 1, path, visited, min_path);
			}
			visited[i] = 0;
		}
	}
}

int Graph::path_len(int *path, int k) {
	int len = 0;
	for (int i = 0; i < k - 1; i++) {
		len += adj[path[i]][path[i + 1]];
	}
	len += adj[path[k - 1]][0]; // 回到起点
	return len;
}

int main() {
	ifstream fin("adj.txt"); // 打开输入文件
	Graph g(fin);			 // 创建图
	fin.close();			 // 关闭输入文件
	cout << g.tsp() << endl; // 计算最短哈密顿回路并输出
	return 0;
}
