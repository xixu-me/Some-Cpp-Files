#include <bits/stdc++.h>

using namespace std;

#define N 1000

void bubble_sort(int arr[], int len) {
	int temp;
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - 1 - i; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main(void) {
	int arr[N] = { 0 };
	int cnt = 0;

	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);

		if (arr[i] == -1) {
			break;
		}
		cnt++;
	}

	bubble_sort(arr, cnt);

	for (int i = 0; i < cnt; i++) {
		if (arr[i] != 0 && arr[i] != -1) {
			printf("%d ", arr[i]);
		}
	}

	printf("\n");

	return 0;
}
