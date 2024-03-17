#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

// 图的邻接矩阵存储
vector<vector<int>> adjMatrix;

// 图的邻接表存储
vector<vector<int>> adjList;

// 图的深度优先遍历
void DFS(int start, vector<bool> &visited) {
	stack<int> s;
	s.push(start);
	visited[start] = true;
	while (!s.empty()) {
		int vertex = s.top();
		s.pop();
		cout << vertex << " ";
		for (int i = 0; i < adjList[vertex].size(); i++) {
			if (!visited[adjList[vertex][i]]) {
				s.push(adjList[vertex][i]);
				visited[adjList[vertex][i]] = true;
			}
		}
	}
}

// 图的广度优先遍历
void BFS(int start, vector<bool> &visited) {
	queue<int> q;
	q.push(start);
	visited[start] = true;
	while (!q.empty()) {
		int vertex = q.front();
		q.pop();
		cout << vertex << " ";
		for (int i = 0; i < adjList[vertex].size(); i++) {
			if (!visited[adjList[vertex][i]]) {
				q.push(adjList[vertex][i]);
				visited[adjList[vertex][i]] = true;
			}
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m; // 输入顶点数和边数
	adjMatrix.resize(n, vector<int>(n, 0));
	adjList.resize(n);
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v; // 输入边的两个顶点
		adjMatrix[u][v] = 1;
		adjMatrix[v][u] = 1;
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}
	vector<bool> visited(n, false);
	DFS(0, visited); // 从顶点0开始深度优先遍历
	cout << endl;
	fill(visited.begin(), visited.end(), false);
	BFS(0, visited); // 从顶点0开始广度优先遍历
	return 0;
}