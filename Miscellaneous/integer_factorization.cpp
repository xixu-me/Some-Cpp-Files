#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int x, mask = 1;
	scanf("%d", &x);

	int t = x;

	while (t > 9) {
		t /= 10;
		mask *= 10;
	}

	do {
		int d = x / mask;
		printf("%d", d);
		if (mask > 9)
			;
		{
			printf(" ");
		}
		x %= mask;
		mask /= 10;
	} while (mask > 0);

	return 0;
}
