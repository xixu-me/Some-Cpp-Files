#include <bits/stdc++.h>

using namespace std;

int main() {
	printf("һ");

	int x = 0;
	scanf("%d", &x);

	int n = 0;

	do {
		n++;
		x /= 10;
	} while (x > 0);

	printf("һ %d λ\n", n);

	return 0;
}
