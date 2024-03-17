// 设计一个类层次，基类为Date，从Date分别派生出ShortE、MediumDate和LongDate.他们各自有成员函数print()，输出当前日期。
// Date输出日期格式为：04-14-2018
// ShortE输出日期格式为：14-04-2018
// MediumDate输出日期格式为：Apr.14,2018
// LongDate输出日期格式为：April 14, 2018

// class Date
// {
// protected:
//     int year, month, day;
// };

#include <bits/stdc++.h>

using namespace std;

class Date {
protected:
	int year, month, day;

public:
	Date() {
		time_t t = time(nullptr);
		tm *lt = localtime(&t);
		year = lt->tm_year + 1900;
		month = lt->tm_mon + 1;
		day = lt->tm_mday;
	}
	void print() { cout << setfill('0') << setw(2) << month << '-' << setw(2) << day << '-' << setw(4) << year << endl; }
};

class ShortE : public Date {
public:
	ShortE() : Date() {}
	void print() { cout << setfill('0') << setw(2) << day << '-' << setw(2) << month << '-' << setw(4) << year << endl; }
};

class MediumDate : public Date {
public:
	MediumDate() : Date() {}
	void print() {
		string months[12] = { "Jan.", "Feb.", "Mar.", "Apr.", "May", "Jun.", "Jul.", "Aug.", "Sep.", "Oct.", "Nov.", "Dec." };
		cout << months[month - 1] << day << ',' << year << endl;
	}
};

class LongDate : public Date {
public:
	LongDate() : Date() {}
	void print() {
		string months[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
		cout << months[month - 1] << ' ' << day << ", " << year << endl;
	}
};

int main() {
	Date d;
	ShortE s;
	MediumDate m;
	LongDate l;

	d.print();
	s.print();
	m.print();
	l.print();

	return 0;
}