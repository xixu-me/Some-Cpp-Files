#include <bits/stdc++.h>

using namespace std;

void bubble_sort(int arr[], int len);

int main(int argc, char const *argv[]) {
	int m;
	scanf("%d", &m);
	int *a = (int *)malloc(m * sizeof(int));
	for (int i = 0; i < m; i++) {
		scanf("%d", &a[i]);
	}

	int n;
	scanf("%d", &n);
	int *b = (int *)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%d", &b[i]);
	}

	int c[40];
	int t = 0, cnt;

	for (int i = 0; i < m; i++) {
		c[i] = a[i];
	}

	for (int j = 0; j < n; j++) {
		cnt = 0;
		for (int i = 0; i < m; i++) {
			if (b[j] != a[i]) {
				cnt++;
			}
			if (cnt == m) {
				c[m + (t++)] = b[j];
			}
		}
	}

	free(a);
	free(b);

	bubble_sort(c, m + t);

	for (int i = 0; i < m + t; i++) {
		printf("%d ", c[i]);
	}

	return 0;
}

void bubble_sort(int arr[], int len) {
	int temp;
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - 1 - i; j++) {
			if (arr[j] < arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
