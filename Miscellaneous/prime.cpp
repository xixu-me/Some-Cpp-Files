#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int m, n;
	int cnt = 0;
	int sum = 0;

	scanf("%d %d", &m, &n);
	if (m == 1) {
		m = 2;
	}

	for (int i = m; i <= n; i++) {
		int isPrime = 1;
		for (int j = 2; j < i - 1; j++) {
			if (i % j == 0) {
				isPrime = 0;
				break;
			}
		}
		if (isPrime) {
			cnt++;
			sum += i;
		}
	}

	printf("%d %d\n", cnt, sum);

	return 0;
}