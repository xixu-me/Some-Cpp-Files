// 1_2.cpp

#include <bits/stdc++.h>

using namespace std;

class Set {
private:
	int *a;
	int cnt;
	int size;

public:
	Set(int = 100);
	int search(int);
	int add(int);
	int del(int);
	void output();
	Set intersection(Set &);
	Set sum(Set &);
	Set difference(Set &);
};

Set::Set(int n) {
	a = new int[n];
	cnt = 0;
	size = n;
}

int Set::search(int x) {
	for (int i = 0; i < cnt; i++)
		if (a[i] == x)
			return i;
	return -1;
}

int Set::add(int x) {
	if (search(x) != -1)
		return 0;
	if (cnt == size)
		return 0;
	a[cnt++] = x;
	return 1;
}

int Set::del(int x) {
	int i = search(x);
	if (i == -1)
		return 0;
	for (int j = i; j < cnt - 1; j++)
		a[j] = a[j + 1];
	cnt--;
	return 1;
}

void Set::output() {
	for (int i = 0; i < cnt; i++)
		cout << a[i] << " ";
	cout << '\n';
}

Set Set::intersection(Set &s) {
	Set t;
	for (int i = 0; i < cnt; i++)
		if (s.search(a[i]) != -1)
			t.add(a[i]);
	return t;
}

Set Set::sum(Set &s) {
	Set t = *this;
	for (int i = 0; i < s.cnt; i++)
		t.add(s.a[i]);
	return t;
}

Set Set::difference(Set &s) {
	Set t;
	for (int i = 0; i < cnt; i++)
		if (s.search(a[i]) == -1)
			t.add(a[i]);
	return t;
}

int main() {
	Set s1, s2;
	s1.add(1);
	s1.add(2);
	s1.add(3);
	s1.add(4);
	s1.add(5);
	s1.add(6);
	s1.add(7);
	s1.add(8);
	s1.add(9);
	s1.add(10);
	cout << "s1: ";
	s1.output();
	s2.add(9);
	s2.add(10);
	s2.add(11);
	s2.add(12);
	s2.add(13);
	s2.add(14);
	s2.add(15);
	cout << "s2: ";
	s2.output();
	Set s3 = s1.intersection(s2);
	cout << "s1 & s2: ";
	s3.output();
	Set s4 = s1.sum(s2);
	cout << "s1 | s2: ";
	s4.output();
	Set s5 = s1.difference(s2);
	cout << "s1 - s2: ";
	s5.output();
	return 0;
}