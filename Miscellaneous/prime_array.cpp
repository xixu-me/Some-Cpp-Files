#include <bits/stdc++.h>

using namespace std;

#define NUMBER 1000

int IsPrime(int x, int KnowPrimes[], int NumberOfKnowPrimes);

int main(void) {
	int prime[NUMBER] = { 2 };
	int cnt = 1;
	int x = 3;

	while (cnt < NUMBER) {
		if (IsPrime(x, prime, cnt)) {
			prime[cnt++] = x;
		}
		x++;
	}

	for (int i = 0; i < NUMBER; i++) {
		printf("%d", prime[i]);

		if ((i + 1) % 5) {
			printf("\t");
		}
		else {
			printf("\n");
		}
	}

	return 0;
}

int IsPrime(int x, int KnowPrimes[], int NumberOfKnowPrimes) {
	int ret = 1;

	for (int i = 0; i < NumberOfKnowPrimes; i++) {
		if (x % KnowPrimes[i] == 0) {
			ret = 0;
			break;
		}
	}

	return ret;
}