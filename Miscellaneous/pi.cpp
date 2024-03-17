#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	double eps;
	double pi;
	double sum = 0;
	int sign = 1;

	scanf("%lf", &eps);

	for (int i = 0;; i++) {
		double x = sign / (sqrt(3) * pow(3, i) * (2 * i + 1));
		sum += sign / (sqrt(3) * pow(3, i) * (2 * i + 1));
		sign = -sign;
		if (1 / (sqrt(3) * pow(3, i) * (2 * i + 1)) < eps)
			break;
	}

	pi = 6 * sum;

	printf("pi=%f\n", pi);

	return 0;
}