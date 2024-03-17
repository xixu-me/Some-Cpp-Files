#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
	int n;

	scanf("%d", &n);

	int *a = (int *)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	int temp;

	for (int i = 0; i < n / 2; i++) {
		temp = a[i];
		a[i] = a[n - i - 1];
		a[n - i - 1] = temp;
	}

	for (int i = 0; i < n; i++) {
		printf("%d ", a[i]);
	}

	free(a);

	return 0;
}
