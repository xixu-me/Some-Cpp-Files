#include <bits/stdc++.h>

using namespace std;

class Teacher {
protected:
	int no;
	string name;
	float salary;
	static int totalno;

public:
	Teacher() {
		no = totalno++;
		cout << "教师姓名:";
		cin >> name;
		salary = 0.0;
	}
	virtual void pay() = 0;
	virtual void display() = 0;
};

int Teacher::totalno = 10000;

class Professor : public Teacher {
private:
	int level;
	float fixed;
	float hourlyrate;
	int classhours;

public:
	Professor(int l) {
		level = l;
		fixed = 0.0;
		hourlyrate = 50.0;
		cout << name << "本月课时：";
		cin >> classhours;
	}
	void pay() {
		if (level == 1)
			fixed = 8000.0;
		else if (level == 2)
			fixed = 7500.0;
		salary = fixed + hourlyrate * classhours;
	}
	void display() {
		cout << "教授：" << name << "，编号：" << no << "，本月工资：" << salary << endl;
	}
};

class AssociateProfessor : public Teacher {
private:
	int level;
	float fixed;
	float hourlyrate;
	int classhours;

public:
	AssociateProfessor(int l) {
		level = l;
		fixed = 0.0;
		hourlyrate = 30.0;
		cout << name << "本月课时：";
		cin >> classhours;
	}
	void pay() {
		if (level == 1)
			fixed = 7000.0;
		else if (level == 2)
			fixed = 6000.0;
		else if (level == 3)
			fixed = 5000.0;
		salary = fixed + hourlyrate * classhours;
	}
	void display() {
		cout << "副教授：" << name << "，编号：" << no << "，本月工资：" << salary << endl;
	}
};

class Lecturer : public Teacher {
private:
	float fixed;
	float hourlyrate;
	int classhours;

public:
	Lecturer() {
		fixed = 4500.0;
		hourlyrate = 20.0;
		cout << "本月课时：";
		cin >> classhours;
	}
	void pay() {
		salary = fixed + hourlyrate * classhours;
	}
	void display() {
		cout << "讲师：" << name << "，编号：" << no << "，本月工资：" << salary << endl;
	}
};

int main() {
	Professor p1(1);
	Professor p2(2);
	AssociateProfessor a1(1);
	AssociateProfessor a2(2);
	AssociateProfessor a3(3);
	Lecturer l;
	Teacher *t[6] = { &p1, &p2, &a1, &a2, &a3, &l };
	cout << "------------------------------------------" << endl;
	cout << "上述教师的基本信息为：" << endl;
	for (int i = 0; i < 6; i++) {
		t[i]->pay();
		t[i]->display();
	}
	return 0;
}