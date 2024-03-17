// 设计一个Circle类，有数据成员radius（半径）、成员函数area()，计算圆的面积。构造一个Circle对象进行测试。

#include <bits/stdc++.h>

using namespace std;

class Circle {
private:
	double radius;

public:
	void setRadius(double r) { radius = r; }
	double area() { return M_PI * radius * radius; }
};

int main() {
	Circle c;

	double r;
	cin >> r;

	c.setRadius(r);

	cout << "Area of circle: " << c.area() << endl;

	return 0;
}