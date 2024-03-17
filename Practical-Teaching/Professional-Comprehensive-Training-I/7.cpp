// Copyright (c) 2023 Xi Xu, All rights reserved.
// SPDX-License-Identifier: GPL-3.0-or-later

#include <bits/stdc++.h>

using namespace std;

class Graph // 定义 Graph 类
{
private:
	int n, e;  // n 表示节点数，e 表示边数
	int **adj; // 邻接矩阵

public:
	Graph(istream &in);							  // 构造函数
	~Graph();									  // 析构函数
	int getn() { return n; }					  // 返回节点数
	void dfs(int v = 0, bool *visited = nullptr); // 深度优先搜索
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

Graph::~Graph() // 析构函数实现
{
	for (size_t i = 0; i < n; i++) // 释放邻接矩阵内存
		delete[] adj[i];
	delete[] adj;
}

void Graph::dfs(int v, bool *visited) // 深度优先搜索实现
{
	visited[v] = true;				  // 标记节点为已访问
	for (size_t i = 0; i < n; i++)	  // 遍历邻接矩阵
		if (adj[v][i] && !visited[i]) // 如果存在边且节点未被访问
			dfs(i, visited);		  // 递归访问节点
}

bool alltrue(bool *arr, int n) // 判断数组中所有元素是否为 true
{
	for (size_t i = 0; i < n; i++)
		if (!arr[i])
			return false;
	return true;
}

int main() {
	ifstream fin("graph.txt");					// 打开文件
	Graph g(fin);								// 创建 Graph 对象 g
	bool visited[g.getn()], outputed[g.getn()]; // 定义 visited 和 outputed 数组
	for (size_t i = 0; i < g.getn(); i++)		// 初始化 visited 和 outputed 数组
	{
		visited[i] = false;
		outputed[i] = false;
	}
	int i = -1;							 // 初始化 i
	while (!alltrue(outputed, g.getn())) // 如果 outputed 数组中有 false
	{
		while (visited[++i]) // 找到第一个未被访问的节点
			;
		g.dfs(i, visited);					  // 从该节点开始深度优先搜索
		for (size_t i = 0; i < g.getn(); i++) // 遍历 visited 数组
			if (visited[i] && !outputed[i])	  // 如果节点被访问且未输出
			{
				cout << i + 1 << " "; // 输出节点编号
				outputed[i] = true;	  // 标记节点为已输出
			}
		cout << endl;
	}
	return 0;
}