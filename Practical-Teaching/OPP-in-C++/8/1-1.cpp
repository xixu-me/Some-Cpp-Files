// 某学校对教师每月工资的计算规定如下：固定工资+课时补贴；教授每课时50元；副教授每课时30元；讲师每课时20元。定义教师抽象类，派生出不同职称的教师类，编写程序求若干个教师的月工资。
// 职称	等级	每月固定工资（元）
// 教授	一级	8000
// 	二级	7500
// 副教授	一级	7000
// 	二级	6000
// 	三级	5000
// 讲师	 	4500

#include <bits/stdc++.h>

using namespace std;

class Teacher {
protected:
	double fixed_salary;
	double class_hour_subsidy;

public:
	double calculate_salary(int class_hours) {
		return fixed_salary + class_hour_subsidy * class_hours;
	}
};

class Professor : public Teacher {
private:
	int level;

public:
	Professor(int l) : level(l) {
		switch (level) {
		case 1:
			fixed_salary = 8000;
			break;
		case 2:
			fixed_salary = 7500;
			break;
		default:
			fixed_salary = 0;
			break;
		}
		class_hour_subsidy = 50;
	}
};

class AssociateProfessor : public Teacher {
private:
	int level;

public:
	AssociateProfessor(int l) : level(l) {
		switch (level) {
		case 1:
			fixed_salary = 7000;
			break;
		case 2:
			fixed_salary = 6000;
			break;
		case 3:
			fixed_salary = 5000;
			break;
		default:
			fixed_salary = 0;
			break;
		}
		class_hour_subsidy = 30;
	}
};

class Lecturer : public Teacher {
public:
	Lecturer() {
		fixed_salary = 4500;
		class_hour_subsidy = 20;
	}
};

int main() {
	Professor p(1), p2(2);
	AssociateProfessor ap(1), ap2(2), ap3(3);
	Lecturer l;
	Teacher *t[7] = { &p, &p2, &ap, &ap2, &ap3, &l };
	for (int i = 0; i < 6; i++) {
		cout << t[i]->calculate_salary(10) << endl;
	}
	return 0;
}