// Copyright (c) 2023 Xi Xu
// SPDX-License-Identifier: GPL-3.0-or-later

#include <bits/stdc++.h>

using namespace std;

// 定义一个图类
class Graph {
private:
	int n, e;  // n表示图中顶点的个数，e表示图中边的个数
	int **adj; // 邻接矩阵

public:
	Graph(istream &in); // 构造函数，从输入流中读取图的信息
	~Graph();			// 析构函数，释放邻接矩阵的内存
	int getn() const {
		return n;
	}											 // 返回图中顶点的个数
	void print() const;							 // 打印邻接矩阵
	bool bfs(int u, int v) const;				 // 判断从顶点u到顶点v是否存在一条路径，使用广度优先搜索算法
	bool dfs(int u, int v, bool *visited) const; // 判断从顶点u到顶点v是否存在一条路径，使用深度优先搜索算法
	bool **warshall() const;					 // 计算图的传递闭包，使用Warshall算法
};

// 构造函数，从输入流in中读取图的信息
Graph::Graph(istream &in) {
	in >> n >> e;		// 读取顶点数和边数
	adj = new int *[n]; // 动态分配邻接矩阵的内存
	for (size_t i = 0; i < n; i++) {
		adj[i] = new int[n];
		for (size_t j = 0; j < n; j++)
			adj[i][j] = 0; // 初始化邻接矩阵
	}
	for (size_t i = 0; i < e; i++) {
		int u, v;
		in >> u >> v;
		adj[u - 1][v - 1]++; // 读取边的信息，更新邻接矩阵
	}
}

// 析构函数，释放邻接矩阵的内存
Graph::~Graph() {
	for (size_t i = 0; i < n; i++)
		delete[] adj[i];
	delete[] adj;
}

// 打印邻接矩阵
void Graph::print() const {
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < n; j++)
			cout << adj[i][j] << " ";
		cout << endl;
	}
}

// 判断从顶点u到顶点v是否存在一条路径，使用广度优先搜索算法
bool Graph::bfs(int u, int v) const {
	if (u == v)
		return true;
	queue<int> q;
	bool visited[n];
	memset(visited, false, sizeof(visited));
	q.push(u);
	visited[u] = true;
	while (!q.empty()) {
		int w = q.front();
		q.pop();
		for (size_t i = 0; i < n; i++)
			if (adj[w][i] && !visited[i]) {
				if (i == v)
					return true;
				q.push(i);
				visited[i] = true;
			}
	}
	return false;
}

// 判断从顶点u到顶点v是否存在一条路径，使用深度优先搜索算法
bool Graph::dfs(int u, int v, bool *visited) const {
	if (u == v)
		return true;
	visited[u] = true;
	for (size_t i = 0; i < n; i++)
		if (adj[u][i] && !visited[i])
			if (dfs(i, v, visited))
				return true;
	return false;
}

// 计算图的传递闭包，使用Warshall算法
bool **Graph::warshall() const {
	bool **rch = new bool *[n];
	for (size_t i = 0; i < n; i++) {
		rch[i] = new bool[n];
		for (size_t j = 0; j < n; j++)
			rch[i][j] = adj[i][j];
		rch[i][i] = true;
	}
	for (size_t k = 0; k < n; k++)
		for (size_t i = 0; i < n; i++)
			for (size_t j = 0; j < n; j++)
				rch[i][j] = rch[i][j] || (rch[i][k] && rch[k][j]);
	return rch;
}

// 主函数
int main() {
	ifstream fin("graph.txt"); // 打开文件
	Graph g(fin);			   // 创建图对象
	fin.close();			   // 关闭文件
	cout << "Adjacency matrix:" << endl;
	g.print(); // 打印邻接矩阵
	cout << "BFS:" << endl;
	for (size_t i = 0; i < g.getn(); i++) {
		for (size_t j = 0; j < g.getn(); j++)
			cout << g.bfs(i, j) << " "; // 判断从顶点i到顶点j是否存在一条路径，使用广度优先搜索算法
		cout << endl;
	}
	cout << "DFS:" << endl;
	for (size_t i = 0; i < g.getn(); i++) {
		for (size_t j = 0; j < g.getn(); j++) {
			bool visited[g.getn()];
			memset(visited, false, sizeof(visited));
			cout << g.dfs(i, j, visited) << " "; // 判断从顶点i到顶点j是否存在一条路径，使用深度优先搜索算法
		}
		cout << endl;
	}
	cout << "Warshall:" << endl;
	bool **rch = g.warshall(); // 计算图的传递闭包，使用Warshall算法
	for (size_t i = 0; i < g.getn(); i++) {
		for (size_t j = 0; j < g.getn(); j++)
			cout << rch[i][j] << " ";
		cout << endl;
	}
	return 0;
}