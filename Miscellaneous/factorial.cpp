#include <bits/stdc++.h>

using namespace std;

int main() {
	int ret = 1;
	int n;
	scanf("%d", &n);

	for (; n > 1; n--) {
		ret *= n;
	}

	printf("%d\n", ret);

	return 0;
}