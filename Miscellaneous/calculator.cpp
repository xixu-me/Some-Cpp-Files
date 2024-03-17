#include <bits/stdc++.h>

using namespace std;

string s;

int change(int l, int r) {

	int sum = 0;

	for (int i = l; i <= r; i++)
		sum = sum * 10 + s[i] - '0';

	return sum;
}

int calc(int l, int r) {

	int cnt = 0, pos1 = -1, pos2 = -1, pos3 = -1;

	for (int i = l; i <= r; i++) {

		if (s[i] == '(')
			cnt++;
		if (s[i] == ')')
			cnt--;

		if (cnt <= 0 && (s[i] == '+' || s[i] == '-'))
			pos1 = i;
		if (cnt <= 0 && (s[i] == '*' || s[i] == '/'))
			pos2 = i;
		if (cnt <= 0 && s[i] == '^')
			pos3 = i;
	}

	if (pos1 == -1 && pos2 == -1 && pos3 == -1 && cnt == 0) {

		if (s[l] == '(')
			return calc(l + 1, r - 1);
		else
			return change(l, r);
	}

	if (pos1 != -1) {

		if (s[pos1] == '+')
			return calc(l, pos1 - 1) + calc(pos1 + 1, r);
		else
			return calc(l, pos1 - 1) - calc(pos1 + 1, r);
	}

	if (pos2 != -1) {

		if (s[pos2] == '*')
			return calc(l, pos2 - 1) * calc(pos2 + 1, r);
		else
			return calc(l, pos2 - 1) / calc(pos2 + 1, r);
	}

	if (pos3 != -1)
		return pow(calc(l, pos3 - 1), calc(pos3 + 1, r));

	if (cnt > 0 && s[l] == '(')
		return calc(l + 1, r);

	if (cnt < 0 && s[l] == ')')
		return calc(l, r - 1);
	return 0;
}

int main() {
	cin >> s;

	cout << calc(0, s.length() - 1);

	return 0;
}