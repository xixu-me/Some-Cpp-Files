#include <bits/stdc++.h>

using namespace std;

int main() {
	printf("x=");

	double x, y;

	scanf("%lf", &x);

	if (x > 0) {
		y = 2 * x;
	}
	else if (x == 0) {
		y = 0;
	}
	else {
		y = -1;
	}

	printf("f(x)=%f\n", y);

	return 0;
}
