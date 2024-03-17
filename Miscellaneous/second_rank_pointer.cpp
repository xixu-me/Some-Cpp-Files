#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
	int i1 = 0, i2 = 1;
	int j1 = 0, j2 = 0;

	int a[][4] = {
		{ 1, 2, 3, 4 },
		{ 5, 6, 7, 8 },
		{ 9, 10, 11, 12 }
	};

	int *p1 = *(a + i1) + j1;
	int *p2 = *(a + i2) + j2;
	int *p3 = *(a + 1);
	int *p4 = a[1];
	int d = p2 - p1;

	int e1 = *p1;
	int e2 = *(*(a + i1) + j1);
	int e3 = a[i1][j1];

	printf("%p: %d\n", p1, e1);
	printf("%p: %d\n", p2, e2);
	printf("p3=%p, p4=%p\n", p3, p4);
	printf("e1 = %d, e2 = %d, e3 = %d\n", e1, e2, e3);
	printf("d = %d\n", d);

	return 0;
}