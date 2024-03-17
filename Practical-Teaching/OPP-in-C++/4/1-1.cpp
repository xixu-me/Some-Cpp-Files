// 设计和实现整型集合类（Set），成员函数要求如下：
// 添加构造函数完成初始化
// 能添加一个元素，元素不重复
// 能删除一个元素
// 输出所有元素
// 求两个集合对象的交集
// 求两个集合对象的并集
// 求两个集合对象的差集

// 1_1.cpp

#include <bits/stdc++.h>

using namespace std;

class Set {
private:
	vector<int> a;

public:
	int search(int);
	int add(int);
	int del(int);
	void output();
	Set operator&(Set &);
	Set operator|(Set &);
	Set operator-(Set &);
};

int Set::search(int x) {
	for (int i = 0; i < a.size(); i++)
		if (a[i] == x)
			return i;
	return -1;
}

int Set::add(int x) {
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

void Set::output() {
	for (int i = 0; i < a.size(); i++) {
		cout << a[i] << ' ';
	}
	cout << '\n';
}

Set Set::operator&(Set &s) {
	Set t;
	for (int i = 0; i < a.size(); i++)
		if (s.search(a[i]) != -1)
			t.add(a[i]);
	return t;
}

Set Set::operator|(Set &s) {
	Set t = *this;
	for (int i = 0; i < s.a.size(); i++)
		t.add(s.a[i]);
	return t;
}

Set Set::operator-(Set &s) {
	Set t;
	for (int i = 0; i < a.size(); i++)
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
	Set s3 = s1 & s2;
	cout << "s1 & s2: ";
	s3.output();
	Set s4 = s1 | s2;
	cout << "s1 | s2: ";
	s4.output();
	Set s5 = s1 - s2;
	cout << "s1 - s2: ";
	s5.output();
	return 0;
}