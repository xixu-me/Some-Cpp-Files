// 改造Set类，重载+（并集）、（-）差集、*（交集）、<<（输出）、>>（输入）和函数调用操作符（添加一个元素）

#include <bits/stdc++.h>

using namespace std;

class Set {
private:
	vector<int> a;

public:
	int search(int);
	int operator()(int x);
	int del(int);
	Set operator*(Set &);
	Set operator+(Set &);
	Set operator-(Set &);
	friend ostream &operator<<(ostream &output, const Set &s);
	friend istream &operator>>(istream &input, Set &s);
};

int Set::search(int x) {
	for (int i = 0; i < a.size(); i++)
		if (a[i] == x)
			return i;
	return -1;
}

int Set::operator()(int x) {
	if (search(x) != -1)
		return 0;
	a.push_back(x);
	return 1;
}

int Set::del(int x) {
	int i = search(x);
	if (i == -1)
		return 0;
	a.erase(a.begin() + i);
	return 1;
}

Set Set::operator*(Set &s) {
	Set t;
	for (int i = 0; i < a.size(); i++)
		if (s.search(a[i]) != -1)
			t(a[i]);
	return t;
}

Set Set::operator+(Set &s) {
	Set t = *this;
	for (int i = 0; i < s.a.size(); i++)
		t(s.a[i]);
	return t;
}

Set Set::operator-(Set &s) {
	Set t;
	for (int i = 0; i < a.size(); i++)
		if (s.search(a[i]) == -1)
			t(a[i]);
	return t;
}

ostream &operator<<(ostream &output, const Set &s) {
	for (int i = 0; i < s.a.size(); i++) {
		output << s.a[i] << ' ';
	}
	return output;
}

istream &operator>>(istream &input, Set &s) {
	s.a.clear();
	int x;
	while (input >> x) {
		s(x);
	}
	return input;
}

int main() {
	Set s1, s2;
	cout << "s1: ";
	cin >> s1;
	s2(9);
	s2(10);
	s2(11);
	s2(12);
	s2(13);
	s2(14);
	s2(15);
	cout << "s2: " << s2 << endl;
	cout << "s1 * s2: " << s1 * s2 << endl;
	cout << "s1 + s2: " << s1 + s2 << endl;
	cout << "s1 - s2: " << s1 - s2 << endl;
	return 0;
}