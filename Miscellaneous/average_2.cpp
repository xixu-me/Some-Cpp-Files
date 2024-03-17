#include <bits/stdc++.h>

using namespace std;

int main() {
	int sum = 0;
	int count = 0;
	int number = 0;

	scanf("%d", &number);

	while (number != -1) {
		sum += number;
		count++;
		scanf("%d", &number);
	}

	double dsum = sum;

	printf("%f\n", dsum / count);
	return 0;
}