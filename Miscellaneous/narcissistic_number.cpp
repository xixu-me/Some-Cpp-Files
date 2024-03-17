#include <bits/stdc++.h>

using namespace std;

int narcissistic(int number);
void PrintN(int m, int n);

int main() {
	int m, n;

	scanf("%d %d", &m, &n);
	if (narcissistic(m))
		printf("%d is a narcissistic number\n", m);
	PrintN(m, n);
	if (narcissistic(n))
		printf("%d is a narcissistic number\n", n);

	return 0;
}

#include <math.h>

int narcissistic(int number) {
	int temp1 = number, temp2 = number;
	int i;

	for (i = 0; temp1 != 0; i++, temp1 /= 10)
		;

	int sum = 0;
	int j = i;

	while (j--) {
		sum += pow(temp2 % 10, i);
		temp2 /= 10;
	}

	if (sum == number) {
		return 1;
	}
	else {
		return 0;
	}
}

void PrintN(int m, int n) {
	for (int i = m + 1; i < n; i++) {
		if (narcissistic(i))
			printf("%d\n", i);
	}
}
