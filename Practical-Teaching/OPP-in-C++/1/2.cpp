// day（0~6）代表每月第一天起始位置，stop代表每月天数，每天之间空两个空格。输入不同的day和stop，输出每月日历的样子。

#include <bits/stdc++.h>

using namespace std;

int main() {
	int day, stop;
	cin >> day >> stop;

	cout << "  Sun  Mon  Tue  Wed  Thu  Fri  Sat" << endl;

	int t = day;
	while (t--) {
		cout << "     ";
	}

	for (int i = 1; i <= stop; i++) {
		cout << setw(5) << i;
		if ((i + day) % 7 == 0) {
			cout << endl;
		}
	}

	return 0;
}