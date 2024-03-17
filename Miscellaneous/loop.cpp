#include <bits/stdc++.h>

using namespace std;

int loop(int x) {
	int y = x;
	int digit = 0;
	int z = 0;
	int ret = 0;

	while (x > 0) {
		digit = x % 10;
		z = z * 10 + digit;
		x /= 10;
	}

	if (y == z) {
		ret = 1;
	}

	return ret;
}

int main(void) {
	int a, b;

	scanf("%d %d", &a, &b);

	for (int i = a; i <= b; i++) {
		if (loop(i) && i % 2 == 0) {
			printf("%d\n", i);
		}
	}

	return 0;
}
