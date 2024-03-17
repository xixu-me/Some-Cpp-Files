// 设计实现一个函数模板，实现任意数据类型的查找

#include <bits/stdc++.h>

using namespace std;

template <typename T>
int find(const T *a, const int &n, const T &x) {
	for (int i = 0; i < n; i++)
		if (a[i] == x)
			return i;
	return -1;
}

int find(const string &s, const char &x) {
	for (int i = 0; i < s.length(); i++)
		if (s[i] == x)
			return i;
	return -1;
}

template <typename T>
int find(const vector<T> &v, const T &x) {
	for (int i = 0; i < v.size(); i++)
		if (v[i] == x)
			return i;
	return -1;
}

int main() {
	int i[5] = { 1, 2, 3, 4, 5 };
	double f[5] = { 1.4, 2.4, 3.4, 4.4, 5.4 };
	string s = "Hello, world!\n";
	vector<int> vi = { 6, 7, 8, 9, 0 };
	vector<double> vd = { 435.6, 57.65, 57.5, 64.5 };
	cout << find(i, 5, 1) << ' ' << find(i, 5, 6) << endl
		 << find(f, 5, 2.4) << ' ' << find(f, 5, 7.5) << endl
		 << find(s, '\n') << ' ' << find(s, 'a') << endl
		 << find(vi, 9) << ' ' << find(vi, 1) << endl
		 << find(vd, 57.5) << ' ' << find(vd, 5.2) << endl;
}