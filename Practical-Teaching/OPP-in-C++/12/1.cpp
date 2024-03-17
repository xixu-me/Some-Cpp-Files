// 写一个程序，将 24 小时格式时间转换为 12 小时格式。定义一个名为 TimeMistake 的异常类，处理用户输入的非法时间，比如 10:65 或者无效字符。

#include <bits/stdc++.h>

using namespace std;

class TimeMistake {
	string message;

public:
	TimeMistake(string msg) { message = msg; }
	string getMessage() { return message; }
};

void test() {
	cout << "Please enter a time in 24-hour format (such as 14:30): ";
	string input;
	cin >> input;
	if (input.length() != 5 || input[2] != ':')
		throw TimeMistake("Invalid time format");
	else {
		int hour = stoi(input.substr(0, 2));
		int min = stoi(input.substr(3, 2));
		if (hour < 0 || hour > 23 || min < 0 || min > 59)
			throw TimeMistake("Invalid time value");
		bool am = true;
		if (hour > 12) {
			am = false;
			hour -= 12;
		}
		if (hour == 0)
			hour = 12;
		cout << "The converted 12 hour format time is: " << setfill('0') << setw(2) << hour << ':' << setw(2) << min << ' ';
		if (am)
			cout << "AM";
		else
			cout << "PM";
	}
}

void handler() {
	try {
		test();
	}
	catch (TimeMistake e) {
		cerr << "An error occurred: " << e.getMessage() << endl;
	}
}

int main() {
	handler();
	return 0;
}