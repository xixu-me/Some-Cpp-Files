#include <bits/stdc++.h>

using namespace std;

int main() {
	double decimal;
	double temp;
	int integer, numerator, denominator;
	int d = -1;
	int g;

	cin >> decimal;

	integer = (int)decimal;
	temp = decimal - integer;

	while ((int)temp % 10 != 0 || (int)temp == 0) {
		temp *= 10;
		d++;
	}

	temp /= 10;

	g = (int)gcd((int)temp, (int)pow(10, d));

	numerator = (int)(temp / g);
	denominator = (int)(pow(10, d) / g);

	cout << integer << numerator << denominator << endl;

	return 0;
}