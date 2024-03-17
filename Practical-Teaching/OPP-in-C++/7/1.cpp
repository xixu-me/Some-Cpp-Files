// Figure 类有一个数据成员radius和虚函数area ()和volume()。从Figure类派生出Sphere类和Column类，分别实现求球体和圆柱体的体积和表面积。并编写测试程序。

#include <bits/stdc++.h>

const double PI = 3.14;

using namespace std;

class Figure {
protected:
	double radius;

public:
	virtual double area() const { return 0.0; }
	virtual double volume() const { return 0.0; }
};

class Sphere : public Figure {
public:
	Sphere(double myr) { radius = myr; }
	virtual double area() const { return 4 * PI * radius * radius; }
	virtual double volume() const { return 4 * PI * radius * radius * radius / 3; }
};

class Column : public Figure {
public:
	Column(double myr, double myh) {
		radius = myr;
		height = myh;
	}
	virtual double area() const { return 2 * PI * radius * height; }
	virtual double volume() const { return PI * radius * radius * height; }

private:
	double height;
};

void func(Figure &p) {
	cout << p.area() << endl;
}

int main() {
	Sphere s(1);
	Column c(1, 2);
	func(s);
	func(c);
	return 0;
}