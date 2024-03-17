// Copyright (c) 2023 徐丞烨，王凯钦，宋析峰，杨崇新
// SPDX-License-Identifier: GPL-3.0-or-later

#include <bits/stdc++.h>

using namespace std;

class Graph {
private:
	int n, e;
	int **adj;

public:
	Graph(istream &in);
	~Graph();
	void print() const;
	bool isEulerian() const;
	void dfs(int u, bool *visited, int v = 0, int w = 0) const;
	bool isBridge(int u, int v) const;
	void fleury() const;
};

Graph::Graph(istream &in) {
	in >> n >> e;
	adj = new int *[n];
	for (size_t i = 0; i < n; i++) {
		adj[i] = new int[n];
		for (size_t j = 0; j < n; j++)
			adj[i][j] = 0;
	}
	for (size_t i = 0; i < e; i++) {
		int u, v;
		in >> u >> v;
		adj[u - 1][v - 1]++;
	}
}

Graph::~Graph() {
	for (size_t i = 0; i < n; i++)
		delete[] adj[i];
	delete[] adj;
}

void Graph::print() const {
	for (size_t i = 0; i < n; i++) {
		for (size_t j = 0; j < n; j++)
			cout << adj[i][j] << " ";
		cout << endl;
	}
}

bool Graph::isEulerian() const {
	for (size_t i = 0; i < n; i++) {
		int sum = 0;
		for (size_t j = 0; j < n; j++)
			sum += adj[i][j];
		for (size_t j = 0; j < n; j++)
			sum -= adj[j][i];
		if (sum != 0)
			return false;
	}
	return true;
}

void Graph::dfs(int u, bool *visited, int v, int w) const {
	visited[u] = true;
	for (size_t i = 0; i < n; i++)
		if (adj[u][i] && !visited[i] && !(u == v && i == w))
			dfs(i, visited, v, w);
}

bool Graph::isBridge(int u, int v) const {
	if (adj[u][v] == 0)
		return false;
	int cnt = 0;
	bool visited[n];
	memset(visited, false, sizeof(visited));
	for (size_t i = 0; i < n; i++)
		if (!visited[i]) {
			dfs(i, visited);
			cnt++;
		}
	memset(visited, false, sizeof(visited));
	for (size_t i = 0; i < n; i++)
		if (!visited[i]) {
			dfs(i, visited, u, v);
			cnt--;
		}
	return cnt < 0;
}

void Graph::fleury() const {
	int copyadj[n][n];
	for (size_t i = 0; i < n; i++)
		for (size_t j = 0; j < n; j++)
			copyadj[i][j] = adj[i][j];
	int u = 0;
	while (true) {
		cout << u + 1 << " ";
		bool flag = false;
		for (size_t v = 0; v < n; v++)
			if (copyadj[u][v] && !isBridge(u, v)) {
				copyadj[u][v]--;
				u = v;
				flag = true;
				break;
			}
		if (!flag)
			break;
	}
}

int main() {
	ifstream fin("graph.txt");
	Graph g(fin);
	fin.close();
	cout << "Adjacency matrix:" << endl;
	g.print();
	bool is = g.isEulerian();
	if (g.isEulerian()) {
		cout << "The graph is Eulerian." << endl;
		g.fleury();
	}
	else
		cout << "The graph is not Eulerian." << endl;
	return 0;
}