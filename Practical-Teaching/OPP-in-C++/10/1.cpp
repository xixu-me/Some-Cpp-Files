// 实现 Set 模板类，并重载 +、<< 和 >> 操作符

#include <bits/stdc++.h>

using namespace std;

template <typename T = int>
class Set {
private:
	vector<T> a;

public:
	int search(const T &) const;
	int operator()(const T &);
	int del(const T &);
	Set<T> operator*(const Set<T> &) const;
	Set<T> operator+(const Set<T> &) const;
	Set<T> operator-(const Set<T> &) const;
	template <typename S>
	friend ostream &operator<<(ostream &output, const Set<S> &s);
	template <typename S>
	friend istream &operator>>(istream &input, Set<S> &s);
};

template <typename T>
int Set<T>::search(const T &x) const {
	for (int i = 0; i < a.size(); i++)
		if (a[i] == x)
			return i;
	return -1;
}

template <typename T>
int Set<T>::operator()(const T &x) {
	if (search(x) != -1)
		return 0;
	a.push_back(x);
	return 1;
}

template <typename T>
int Set<T>::del(const T &x) {
	int i = search(x);
	if (i == -1)
		return 0;
	a.erase(a.begin() + i);
	return 1;
}

template <typename T>
Set<T> Set<T>::operator*(const Set<T> &s) const {
	Set<T> t;
	for (int i = 0; i < a.size(); i++)
		if (s.search(a[i]) != -1)
			t(a[i]);
	return t;
}

template <typename T>
Set<T> Set<T>::operator+(const Set<T> &s) const {
	Set t = *this;
	for (int i = 0; i < s.a.size(); i++)
		t(s.a[i]);
	return t;
}

template <typename T>
Set<T> Set<T>::operator-(const Set<T> &s) const {
	Set t;
	for (int i = 0; i < a.size(); i++)
		if (s.search(a[i]) == -1)
			t(a[i]);
	return t;
}

template <typename T>
ostream &operator<<(ostream &output, const Set<T> &s) {
	for (int i = 0; i < s.a.size(); i++)
		output << s.a[i] << ' ';
	return output;
}

template <typename T>
istream &operator>>(istream &input, Set<T> &s) {
	s.a.clear();
	int x;
	while (input >> x)
		s(x);
	return input;
}

int main() {
	Set<int> s1, s2;
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