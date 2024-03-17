#include <bits/stdc++.h>

using namespace std;

void quick_sort(int *arr, int left, int right) {
	if (left >= right) {
		return;
	}

	int pivot = arr[(left + right) / 2];
	int i = left - 1;
	int j = right + 1;

	while (1) {
		do {
			i++;
		} while (arr[i] < pivot);

		do {
			j--;
		} while (arr[j] > pivot);

		if (i >= j) {
			break;
		}

		int temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}

	quick_sort(arr, left, j);
	quick_sort(arr, j + 1, right);
}

int main() {
	int n;

	cout << "请输入将要被排序的整数的个数：";

	cin >> n;

	cout << "请输入将要被排序的整数，其间以空格隔开：";

	int arr[n];

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	quick_sort(arr, 0, n - 1);

	cout << "经过快速排序后的结果是：";

	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}

	cout << '\n';

	return 0;
}