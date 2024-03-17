// 设计一个函数print打印字符串，如果只传string型参数s，则字符串长度跟10比较，大于10，打印前10个字符，小于10，全部输出s；如果传string型参数s和int型n，则字符串长度跟n比较，大于n，打印前n个字符，小于n，全部输出s。

#include <bits/stdc++.h>

using namespace std;

void print(string s, int n = 10) {
	cout << s.substr(0, n) << endl;
}

int main() {
	string s;
	int n;

	cin >> s;
	print(s);

	cin >> s >> n;
	print(s, n);

	return 0;
}