#include <bits/stdc++.h>

using namespace std;

int main(void) {
	const int N = 9;

	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= i; j++) {
			printf("%d * %d = %d", i, j, i * j);
			if (i * j < 10) {
				printf("    ");
			}
			else {
				printf("   ");
			}
		}
		printf("\n");
	}

	return 0;
}