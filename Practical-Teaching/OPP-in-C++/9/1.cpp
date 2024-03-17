// 定义一个有理数类。一个有理数类是一个可以表示成两个整数相除的数，如1/2、2/3、4/5。一个有理数类有两个整数成员表示：分子和分母。要求能检测分母为0问题，能化简，重载+、-、*、/运算符完成四则运算，重载“==”符号判断两个有理数是否相等

#include <bits/stdc++.h>

using namespace std;

class Rational {
private:
	int numerator;
	int denominator;

public:
	Rational(int num, int den);
	Rational operator+(const Rational &r) const;
	Rational operator-(const Rational &r) const;
	Rational operator*(const Rational &r) const;
	Rational operator/(const Rational &r) const;
	bool operator==(const Rational &r) const;
	friend ostream &operator<<(ostream &output, const Rational &r);
};

Rational::Rational(int num, int den) {
	numerator = num;
	denominator = den;
	if (numerator == 0 && denominator == 0)
		;
	else if (numerator == 0)
		denominator = 1;
	else if (denominator == 0)
		numerator = 1;
	else {
		int _gcd = gcd(numerator, denominator);
		numerator /= _gcd;
		denominator /= _gcd;
		if (denominator < 0) {
			numerator *= -1;
			denominator *= -1;
		}
	}
}

Rational Rational::operator+(const Rational &r) const {
	int num, den;
	if (numerator != 0 && r.numerator != 0 && denominator == 0 && r.denominator == 0) {
		num = 1;
		den = 0;
	}
	else {
		num = numerator * r.denominator + r.numerator * denominator;
		den = denominator * r.denominator;
	}
	return Rational(num, den);
}

Rational Rational::operator-(const Rational &r) const {
	int num = numerator * r.denominator - r.numerator * denominator;
	int den = denominator * r.denominator;
	return Rational(num, den);
}

Rational Rational::operator*(const Rational &r) const {
	int num = numerator * r.numerator;
	int den = denominator * r.denominator;
	return Rational(num, den);
}

Rational Rational::operator/(const Rational &r) const {
	int num, den;
	if (denominator == 0 && r.denominator == 0) {
		num = 0;
		den = 0;
	}
	else {
		num = numerator * r.denominator;
		den = r.numerator * denominator;
	}
	return Rational(num, den);
}

bool Rational::operator==(const Rational &r) const {
	return numerator == r.numerator && denominator == r.denominator;
}

ostream &operator<<(ostream &output, const Rational &r) {
	if (r.numerator == 0 && r.denominator == 0)
		output << "NaN";
	else if (r.denominator == 0)
		output << "Inf";
	else
		output << r.numerator << " / " << r.denominator;
	return output;
}

int main() {
	char c;
	int num1, den1, num2, den2;
	cout << "r1 = ";
	cin >> num1 >> c >> den1;
	cout << "r2 = ";
	cin >> num2 >> c >> den2;
	Rational r1(num1, den1), r2(num2, den2);
	cout << "r1 + r2 = " << r1 + r2 << endl
		 << "r1 - r2 = " << r1 - r2 << endl
		 << "r1 * r2 = " << r1 * r2 << endl
		 << "r1 / r2 = " << r1 / r2 << endl;
	if (r1 == r2)
		cout << "r1 == r2" << endl;
	else
		cout << "r1 != r2" << endl;
	return 0;
}