#include <bits/stdc++.h>

using namespace std;

int main() {
	printf("x=");

	double x, y;
	int type;

	scanf("%lf", &x);

	type = x < 0;

	switch (type) {
	case 1:
		y = -1;
		break;

	case 0:
		y = 2 * x;
		break;
	}

	printf("f(x)=%f\n", y);

	return 0;
}
