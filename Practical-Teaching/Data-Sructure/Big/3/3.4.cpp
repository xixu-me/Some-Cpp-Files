#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define INF INT_MAX
#define N 6

void Dijkstra(int graph[N][N], int start) {
	vector<int> dist(N, INF);
	dist[start] = 0;
	vector<bool> visited(N, false);
	vector<int> prev(N, -1);

	for (int count = 0; count < N - 1; count++) {
		int min = INF, min_index;
		for (int v = 0; v < N; v++)
			if (!visited[v] && dist[v] <= min)
				min = dist[v], min_index = v;

		int u = min_index;
		visited[u] = true;

		for (int v = 0; v < N; v++)
			if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
				dist[v] = dist[u] + graph[u][v];
				prev[v] = u;
			}
	}

	for (int i = 0; i < N; i++) {
		if (i != start) {
			cout << "Path from " << start << " to " << i << ": ";
			if (dist[i] == INF) {
				cout << "No path\n";
			}
			else {
				vector<int> path;
				for (int j = i; j != -1; j = prev[j])
					path.push_back(j);
				for (int j = path.size() - 1; j > 0; j--)
					cout << path[j] << " -> ";
				cout << path[0] << " (Cost: " << dist[i] << ")\n";
			}
		}
	}
}

int main() {
	int graph[N][N] = {
		{ 0, 0, 10, 0, 30, 100 },
		{ 0, 0, 5, 0, 0, 0 },
		{ 0, 0, 0, 50, 0, 0 },
		{ 0, 0, 0, 0, 0, 10 },
		{ 0, 0, 0, 20, 0, 60 },
		{ 0, 0, 0, 0, 0, 0 }
	};

	for (int i = 0; i < N; i++)
		Dijkstra(graph, i);

	return 0;
}