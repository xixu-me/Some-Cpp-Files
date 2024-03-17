#include <bits/stdc++.h>

using namespace std;

struct Date {
	int year;
	int month;
	int day;
} d1, d2;

int m[2][13] = {
	{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
	{ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};

int count(struct Date *p_d);

int main(int argc, char *argv[]) {
	int ans = 0;

	scanf("%d %d %d", &d1.year, &d1.month, &d1.day);
	scanf("%d %d %d", &d2.year, &d2.month, &d2.day);

	for (int i = d1.year; i < d2.year; i++) {
		if ((i % 100 != 0 && i % 4 == 0) || i % 400 == 0)
			ans += 366;
		else
			ans += 365;
	}

	ans += count(&d2) - count(&d1);

	printf("%d\n", ans);

	return 0;
}

int count(struct Date *p_d) {
	int n = 0;

	if ((p_d->year % 100 != 0 && p_d->year % 4 == 0) || p_d->year % 400 == 0)
		for (int i = 1; i < p_d->month; i++)
			n += m[1][i];
	else
		for (int i = 1; i < p_d->month; i++)
			n += m[0][i];

	return n + p_d->day;
}