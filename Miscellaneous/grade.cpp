#include <bits/stdc++.h>

using namespace std;

int main() {
	int grade = 0;

	scanf("%d", &grade);

	grade /= 10;

	switch (grade) {
	case 10:
	case 9:
		printf("A\n");
		break;

	case 8:
		printf("B\n");
		break;

	case 7:
		printf("C\n");
		break;

	case 6:
		printf("D\n");
		break;

	default:
		printf("F\n");
	}

	return 0;
}
