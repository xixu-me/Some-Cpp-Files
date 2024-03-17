#include <bits/stdc++.h>

using namespace std;

class Complex {
private:
	double real;
	double imag;

public:
	Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}

	bool operator==(const Complex &c) const {
		return real == c.real && imag == c.imag;
	}

	double operator!() const {
		return sqrt(real * real + imag * imag);
	}

	Complex operator~() const {
		return Complex(real, -imag);
	}

	friend istream &operator>>(istream &input, Complex &c) {
		string si;
		input >> si;
		stringstream i(si);
		char sign;
		i >> c.real >> sign >> c.imag;
		if (sign == '-')
			c.imag = -c.imag;
		return input;
	}

	friend ostream &operator<<(ostream &output, const Complex &c) {
		if (c.imag > 0)
			output << c.real << " + " << c.imag << "i";
		else if (c.imag < 0)
			output << c.real << " - " << -c.imag << "i";
		else
			output << c.real;
		return output;
	}
};

int main() {
	Complex c1;
	Complex c2;
	cout << "c1 = ";
	cin >> c1;
	cout << "c2 =";
	cin >> c2;
	cout << "|c1| = " << !c1 << endl;
	cout << "|c2| = " << !c2 << endl;
	cout << "~c1 = " << ~c1 << endl;
	cout << "~c2 = " << ~c2 << endl;
	if (c1 == c2) {
		cout << "c1 == c2" << endl;
	}
	else {
		cout << "c1 != c2" << endl;
	}

	return 0;
}