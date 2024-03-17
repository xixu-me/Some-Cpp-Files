#include <bits/stdc++.h>

using namespace std;

void hanoi(int n, char a, char b, char c);

int main(int argc, char const *argv[]) {
	int n;

	printf("input the number of disk: ");

	scanf("%d", &n);

	printf("the steps for %d disk are:\n", n);

	hanoi(n, 'A', 'B', 'C');

	return 0;
}

// 搬动 n 个盘， 从 a 到 b，c 为中间过渡
void hanoi(int n, char a, char b, char c) {
	if (n == 1) {
		printf("%c-->%c\n", a, b);
	}
	else {
		hanoi(n - 1, a, c, b);
		printf("%c-->%c\n", a, c);
		hanoi(n - 1, c, b, a);
	}
}