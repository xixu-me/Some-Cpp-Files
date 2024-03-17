#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int n;
	double sum = 0.0;
	double sign = 1.0;

	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		sum += sign / i;
		sign = -sign;
	}

	printf("f (%d) = %f\n", n, sum);

	return 0;
}