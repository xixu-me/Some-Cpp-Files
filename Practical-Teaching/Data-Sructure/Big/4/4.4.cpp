#include <vector>
#include <iostream>

using namespace std;

// 选择排序
void selectionSort(vector<int> &nums) {
	int n = nums.size();
	for (int i = 0; i < n; i++) {
		int minIndex = i;
		for (int j = i + 1; j < n; j++) {
			if (nums[j] < nums[minIndex]) {
				minIndex = j;
			}
		}
		swap(nums[i], nums[minIndex]);
	}
}

// 插入排序
void insertionSort(vector<int> &nums) {
	int n = nums.size();
	for (int i = 1; i < n; i++) {
		int key = nums[i];
		int j = i - 1;
		while (j >= 0 && nums[j] > key) {
			nums[j + 1] = nums[j];
			j--;
		}
		nums[j + 1] = key;
	}
}

// 归并排序
void merge(vector<int> &nums, int left, int mid, int right) {
	vector<int> temp(right - left + 1);
	int i = left, j = mid + 1, k = 0;
	while (i <= mid && j <= right) {
		temp[k++] = nums[i] <= nums[j] ? nums[i++] : nums[j++];
	}
	while (i <= mid) {
		temp[k++] = nums[i++];
	}
	while (j <= right) {
		temp[k++] = nums[j++];
	}
	for (int i = left; i <= right; i++) {
		nums[i] = temp[i - left];
	}
}

void mergeSort(vector<int> &nums, int left, int right) {
	if (left < right) {
		int mid = left + (right - left) / 2;
		mergeSort(nums, left, mid);
		mergeSort(nums, mid + 1, right);
		merge(nums, left, mid, right);
	}
}

// 单指针快速排序
int partitionSingle(vector<int> &nums, int left, int right) {
	int pivot = nums[right];
	int i = left;
	for (int j = left; j < right; j++) {
		if (nums[j] < pivot) {
			swap(nums[i], nums[j]);
			i++;
		}
	}
	swap(nums[i], nums[right]);
	return i;
}

void quickSortSingle(vector<int> &nums, int left, int right) {
	if (left < right) {
		int pivotIndex = partitionSingle(nums, left, right);
		quickSortSingle(nums, left, pivotIndex - 1);
		quickSortSingle(nums, pivotIndex + 1, right);
	}
}

// 双指针快速排序
int partitionDouble(vector<int> &nums, int left, int right) {
	int pivot = nums[left];
	while (left < right) {
		while (left < right && nums[right] >= pivot) {
			right--;
		}
		nums[left] = nums[right];
		while (left < right && nums[left] <= pivot) {
			left++;
		}
		nums[right] = nums[left];
	}
	nums[left] = pivot;
	return left;
}

void quickSortDouble(vector<int> &nums, int left, int right) {
	if (left < right) {
		int pivotIndex = partitionDouble(nums, left, right);
		quickSortDouble(nums, left, pivotIndex - 1);
		quickSortDouble(nums, pivotIndex + 1, right);
	}
}

// 主函数，用于测试上述排序算法
int main() {
	vector<int> arr;
	int n;
	cout << "请输入你想要排序的数字的数量：";
	cin >> n;
	cout << "请输入这些数字（用空格隔开）：";
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}

	selectionSort(arr);
	cout << "选择排序后的数组：";
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << "\n";

	insertionSort(arr);
	cout << "插入排序后的数组：";
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << "\n";

	mergeSort(arr, 0, arr.size() - 1);
	cout << "归并排序后的数组：";
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << "\n";

	quickSortSingle(arr, 0, arr.size() - 1);
	cout << "单指针快速排序后的数组：";
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << "\n";

	quickSortDouble(arr, 0, arr.size() - 1);
	cout << "双指针快速排序后的数组：";
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << "\n";

	return 0;
}
