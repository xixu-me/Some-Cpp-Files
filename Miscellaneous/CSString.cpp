// 模仿c++ 自带string类，设计一个字符串类SString，要求至少有以下功能：
// （1）字符串初始化
// （2）字符串类对象能相互赋值（重载运算符 =）
// （3）获得字符串长度
// （4）字符串连接，通过重载运算符 + 实现
// （5）字符串显示功能
// （6）字符串插入功能
// （7）字符串删除功能
// （8）取子串功能
// （9）字符串查找功能
// （10）字符串比较功能，重载运算符 ==

#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 2;

class SString {
private:
	char *p;
	int len;

public:
	SString();
	SString(const char *s);
	SString(const SString &s);

	~SString();

	SString &operator=(const char *s);
	SString &operator=(const SString &s);

	SString operator+(const char *s) const;
	SString operator+(const SString &s) const;

	bool operator==(const char *s) const;
	bool operator==(const SString &s) const;

	int length() const;

	void insert(int pos, const char *s);
	void insert(int pos, const SString &s);

	void erase(int pos, int n);

	SString substr(int pos, int n) const;

	int find(const char *s) const;
	int find(const SString &s) const;

	friend ostream &operator<<(ostream &out, const SString &s);
	friend istream &operator>>(istream &in, SString &s);
};

ostream &operator<<(ostream &out, const SString &s);

SString::SString() {
	p = nullptr;
	len = 0;
}

SString::SString(const char *s) {
	len = strlen(s);
	p = new char[len + 1];
	strcpy(p, s);
}

SString::SString(const SString &s) {
	len = s.len;
	p = new char[len + 1];
	strcpy(p, s.p);
}

SString::~SString() {
	delete[] p;
}

SString &SString::operator=(const char *s) {
	if (p != s) {
		delete[] p;
		len = strlen(s);
		p = new char[len + 1];
		strcpy(p, s);
	}
	return *this;
}

SString &SString::operator=(const SString &s) {
	if (this != &s) {
		delete[] p;
		len = s.len;
		p = new char[len + 1];
		strcpy(p, s.p);
	}
	return *this;
}

SString SString::operator+(const char *s) const {
	SString temp;
	temp.len = len + strlen(s);
	temp.p = new char[temp.len + 1];
	strcpy(temp.p, p);
	strcat(temp.p, s);
	return temp;
}

SString SString::operator+(const SString &s) const {
	return *this + s.p;
}

bool SString::operator==(const char *s) const {
	return strcmp(p, s) == 0;
}

bool SString::operator==(const SString &s) const {
	return *this == s.p;
}

int SString::length() const {
	return len;
}

void SString::insert(int pos, const char *s) {
	if (pos < 0 || pos > len) {
		cerr << "Invalid position" << endl;
		return;
	}
	int slen = strlen(s);
	char *temp = new char[len + slen + 1];
	strncpy(temp, p, pos);
	strcpy(temp + pos, s);
	strcpy(temp + pos + slen, p + pos);
	delete[] p;
	p = temp;
	len += slen;
}

void SString::insert(int pos, const SString &s) {
	insert(pos, s.p);
}

void SString::erase(int pos, int n) {
	if (pos < 0 || pos >= len || n < 0 || n > len - pos) {
		cerr << "Invalid arguments" << endl;
		return;
	}
	char *temp = new char[len - n + 1];
	strncpy(temp, p, pos);
	strcpy(temp + pos, p + pos + n);
	delete[] p;
	p = temp;
	len -= n;
}

SString SString::substr(int pos, int n) const {
	if (pos < 0 || pos >= len || n < 0 || n > len - pos) {
		cerr << "Invalid arguments" << endl;
		return SString();
	}
	char *temp = new char[n + 1];
	strncpy(temp, p + pos, n);
	temp[n] = '\0';
	SString result(temp);
	delete[] temp;
	return result;
}

int SString::find(const char *s) const {
	char *pos = strstr(p, s);
	if (pos == nullptr) {
		return -1;
	}
	else {
		return pos - p;
	}
}

int SString::find(const SString &s) const {
	return find(s.p);
}

ostream &operator<<(ostream &out, const SString &s) {
	out << s.p;
	return out;
}

istream &operator>>(istream &in, SString &s) {
	char t[N];
	in >> t;
	s.len = strlen(t);
	s.p = new char[s.len + 1];
	strcpy(s.p, t);
	return in;
}