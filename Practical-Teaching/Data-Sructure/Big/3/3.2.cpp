#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 1e9;
const int N = 6;
double graph[N][N] = {
	{ 0, 0.6, 0.1, 0.5, 0, 0 },
	{ 0.6, 0, 0.5, 0, 0.3, 0 },
	{ 0.1, 0.5, 0, 0.5, 0.6, 0.4 },
	{ 0.5, 0, 0.5, 0, 0, 0.2 },
	{ 0, 0.3, 0.6, 0, 0, 0.6 },
	{ 0, 0, 0.4, 0.2, 0.6, 0 }
};

// Prim's Algorithm
void prim() {
	vector<bool> selected(N, false);
	vector<double> minWeight(N, MAX);
	minWeight[0] = 0;
	for (int i = 0; i < N; ++i) {
		int u = -1;
		for (int j = 0; j < N; ++j) {
			if (!selected[j] && (u == -1 || minWeight[j] < minWeight[u])) {
				u = j;
			}
		}
		selected[u] = true;
		for (int v = 0; v < N; ++v) {
			if (!selected[v] && graph[u][v] != 0 && graph[u][v] < minWeight[v]) {
				minWeight[v] = graph[u][v];
			}
		}
	}
	double totalWeight = 0;
	for (int i = 0; i < N; ++i) {
		totalWeight += minWeight[i];
	}
	cout << "Minimum cost with Prim's Algorithm: " << totalWeight << endl;
}

// Kruskal's Algorithm
struct Edge {
	int u, v;
	double weight;
	bool operator<(const Edge &other) const {
		return weight < other.weight;
	}
};

int parent[N];
int find(int x) {
	if (x != parent[x]) {
		parent[x] = find(parent[x]);
	}
	return parent[x];
}

void unionSet(int x, int y) {
	parent[find(x)] = find(y);
}

void kruskal() {
	vector<Edge> edges;
	for (int i = 0; i < N; ++i) {
		for (int j = i + 1; j < N; ++j) {
			if (graph[i][j] > 0) {
				edges.push_back({ i, j, graph[i][j] });
			}
		}
	}
	sort(edges.begin(), edges.end());
	for (int i = 0; i < N; ++i) {
		parent[i] = i;
	}
	double totalWeight = 0;
	for (const Edge &edge : edges) {
		if (find(edge.u) != find(edge.v)) {
			totalWeight += edge.weight;
			unionSet(edge.u, edge.v);
		}
	}
	cout << "Minimum cost with Kruskal's Algorithm: " << totalWeight << endl;
}

int main() {
	prim();
	kruskal();
	return 0;
}