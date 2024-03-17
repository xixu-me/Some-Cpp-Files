#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 输入数组元素的函数
vector<int> inputArray(int n) {
	vector<int> arr;
	int temp;

	cout << "请输入数组的元素：";
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr.push_back(temp);
	}

	return arr;
}

// 方案一：使用优先队列
void heapSortUsingPriorityQueue(vector<int> &arr) {
	priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.end());

	int i = 0;
	while (!pq.empty()) {
		arr[i++] = pq.top();
		pq.pop();
	}
}

// 方案二：使用向下过滤函数
void heapify(vector<int> &arr, int n, int i) {
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && arr[left] > arr[largest])
		largest = left;

	if (right < n && arr[right] > arr[largest])
		largest = right;

	if (largest != i) {
		swap(arr[i], arr[largest]);
		heapify(arr, n, largest);
	}
}

void heapSort(vector<int> &arr) {
	int n = arr.size();

	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	for (int i = n - 1; i >= 0; i--) {
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
}

void printArray(vector<int> &arr) {
	for (int i = 0; i < arr.size(); ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

int main() {
	int n;

	cout << "请输入数组的元素个数：";
	cin >> n;

	vector<int> arr = inputArray(n);
	heapSortUsingPriorityQueue(arr);
	cout << "Sorted array using priority queue is \n";
	printArray(arr);

	arr = inputArray(n);
	heapSort(arr);
	cout << "Sorted array using heapify is \n";
	printArray(arr);
}
