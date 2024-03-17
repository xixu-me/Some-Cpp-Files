#include <bits/stdc++.h>

using namespace std;

int fabonacci(int n);

int main(void) {
	int n;

	scanf("%d", &n);

	printf("%d\n", fabonacci(n));

	return 0;
}

int fabonacci(int n) {
	int ret;

	if (n == 0 || n == 1) {
		ret = n;
	}
	else {
		ret = fabonacci(n - 1) + fabonacci(n - 2);
	}

	return ret;
}