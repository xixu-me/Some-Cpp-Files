// 编程实现Student类，在该类中设计静态数据成员segment1、segment2、segment3、segment4、segment5分别统计分数100-90、89-80,、79-70、69-60、59-0学生人数。设计静态成员函数display()显示各分数段人数。

#include <bits/stdc++.h>

using namespace std;

class Student {
private:
	static int segment1;
	static int segment2;
	static int segment3;
	static int segment4;
	static int segment5;

public:
	Student(int score);
	static void display();
};

int Student::segment1 = 0;
int Student::segment2 = 0;
int Student::segment3 = 0;
int Student::segment4 = 0;
int Student::segment5 = 0;

Student::Student(int score) {
	if (score >= 90 && score <= 100)
		segment1++;
	else if (score >= 80 && score < 90)
		segment2++;
	else if (score >= 70 && score < 80)
		segment3++;
	else if (score >= 60 && score < 70)
		segment4++;
	else if (score >= 0 && score < 60)
		segment5++;
	else
		cout << "Invalid score: " << score << endl;
}

void Student::display() {
	cout << "Segment1: " << segment1 << endl;
	cout << "Segment2: " << segment2 << endl;
	cout << "Segment3: " << segment3 << endl;
	cout << "Segment4: " << segment4 << endl;
	cout << "Segment5: " << segment5 << endl;
}

int main() {
	Student s0(115);
	Student s1(95);
	Student s2(85);
	Student s3(75);
	Student s4(65);
	Student s5(55);
	Student s6(45);
	Student::display();
	return 0;
}