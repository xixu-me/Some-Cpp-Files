#include <bits/stdc++.h>

using namespace std;

int main() {
	int h, w;

	scanf("%d %d", &h, &w);

	int a[h][w], b[w][h];

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	for (int i = 0; i < w; i++) {
		for (int j = 0; j < h; j++) {
			b[i][j] = a[j][i];
		}
	}

	return 0;
}
