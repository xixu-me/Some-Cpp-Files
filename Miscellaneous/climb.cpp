#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main(void) {
	int n, n1 = 0, n2 = 1, ret = 2;

	scanf("%d", &n);

	if (n < 3) {
		printf("%d\n", n);
	}
	else {
		for (int i = 2; i < n; i++) {
			n1 = n2;
			n2 = ret;
			ret = n1 + n2;
		}
		printf("%d\n", ret);
	}

	return 0;
}