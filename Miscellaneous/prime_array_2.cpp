#include <bits/stdc++.h>

using namespace std;

#define N 100

int main(void) {
	int prime[N];

	for (int i = 0; i < N; i++) {
		prime[i] = 1;
	}

	for (int x = 2; x < N; x++) {
		if (prime[x]) {
			for (int i = 2; x * i < N; i++) {
				prime[x * i] = 0;
			}
		}
	}

	for (int i = 2; i < N; i++) {
		if (prime[i]) {
			printf("%d ", i);
		}
	}

	return 0;
}
