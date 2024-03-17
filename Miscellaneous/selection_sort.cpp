#include <bits/stdc++.h>

using namespace std;

void swap(int *a, int *b);

void selection_sort(int *a, int len);

int main(int argc, char const *argv[]) {
	int m;
	scanf("%d", &m);
	int *a = (int *)malloc(m * sizeof(int));
	for (int i = 0; i < m; i++) {
		scanf("%d", &a[i]);
	}

	selection_sort(a, m);

	for (int i = 0; i < m; i++) {
		printf("%d ", a[i]);
	}

	free(a);

	return 0;
}

void selection_sort(int *arr, int len) {
	int i, j;

	for (i = 0; i < len - 1; i++) {
		int max = i;
		for (j = i + 1; j < len; j++)
			if (arr[j] > arr[max])
				max = j;
		swap(&arr[max], &arr[i]);
	}
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
