#include <bits/stdc++.h>

using namespace std;

// int gcd(int m, int n)
// {
//     while (n != 0)
//     {
//         int t = m % n;
//         m = n;
//         n = t;
//     }
//     return m;
// }

class Rational {
private:
	int numerator;
	int denominator;

public:
	Rational(int num, int den);
	friend ostream &operator<<(ostream &output, const Rational &r);
	Rational operator+(const Rational &r) const;
	Rational operator-(const Rational &r) const;
	Rational operator*(const Rational &r) const;
	Rational operator/(const Rational &r) const;
	bool operator==(const Rational &r) const;
	bool operator>(const Rational &r) const;
	Rational operator~() const;
	Rational operator!() const;
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

ostream &operator<<(ostream &output, const Rational &r) {
	if (r.numerator == 0 && r.denominator == 0)
		output << "NaN";
	else if (r.denominator == 0)
		output << "Inf";
	else
		output << r.numerator << " / " << r.denominator;
	return output;
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

bool Rational::operator>(const Rational &r) const {
	return 1.0 * numerator / denominator > 1.0 * r.numerator / r.denominator;
}

Rational Rational::operator~() const {
	return Rational(-numerator, denominator);
}

Rational Rational::operator!() const {
	int num = denominator, den = numerator;
	if (den < 0) {
		num *= -1;
		den *= -1;
	}
	return Rational(num, den);
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
		 << "r1 / r2 = " << r1 / r2 << endl
		 << "~r1 = " << ~r1 << ", "
		 << "~r2 = " << ~r2 << endl
		 << "!r1 = " << !r1 << ", "
		 << "!r2 = " << !r2 << endl;
	if (r1 == r2)
		cout << "r1 == r2" << endl;
	else if (r1 > r2)
		cout << "r1 > r2" << endl;
	else
		cout << "r1 < r2" << endl;
	return 0;
}