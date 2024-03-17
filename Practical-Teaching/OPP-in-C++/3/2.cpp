// 字符串序列类的设计：类Sequence的定义

#include <bits/stdc++.h>

using namespace std;

class Sequence {
private:
	int last;
	string s[100];

public:
	void init();
	void append(string);
	void del(string);
	void output();
};

void Sequence::init() {
	last = -1;
}

void Sequence::append(string x) {
	s[++last] = x;
}

void Sequence::del(string x) {
	for (int i = 0; i <= last; i++)
		if (s[i] == x) {
			for (int j = i; j < last; j++)
				s[j] = s[j + 1];

			last--;
			break;
		}
}

void Sequence::output() {
	for (int i = 0; i <= last; i++)
		cout << s[i] << ' ';

	cout << '\n';
}

int main() {
	Sequence seq;
	seq.init();
	seq.append("a");
	seq.append("b");
	seq.append("c");
	seq.append("d");
	seq.append("e");
	seq.append("f");
	seq.append("g");
	seq.append("h");
	seq.output();
	seq.del("b");
	seq.del("d");
	seq.del("f");
	seq.del("h");
	seq.output();
	return 0;
}