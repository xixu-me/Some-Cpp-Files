// 输入若干数据，找出最大值输出。（从键盘和文件读取两种方式）

#include <bits/stdc++.h>

using namespace std;

int main() {
	double max;
	cin >> max;

	double i;
	while (cin >> i)
		if (i > max)
			max = i;

	cout << max << endl;

	return 0;
}