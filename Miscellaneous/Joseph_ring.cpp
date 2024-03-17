#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **argv) {
	int n, m;

	scanf("%d %d", &n, &m);

	int out[n];

	for (int i = 0; i < n; i++) {
		out[i] = 0;
	}

	int i = 0, cnt = 0, r = 1;

	while (r < n) {
		if (!out[i]) {
			cnt++;
		}

		if (cnt == m) {
			cnt = 0;
			out[i] = 1;
			r++;
		}

		i++;

		if (i > n - 1) {
			i = i % n;
		}
	}

	for (int i = 0; i < n; i++) {
		if (!out[i]) {
			printf("%d\n", i + 1);
		}
	}

	return 0;
}