#include <bits/stdc++.h>

using namespace std;

#define NUMBER 10

int main(void) {
	int cnt[NUMBER];
	int x;

	for (int i = 0; i < NUMBER; i++) {
		cnt[i] = 0;
	}

	scanf("%d", &x);

	while (x != -1) {
		if (x >= 0 && x <= 9) {
			cnt[x]++;
		}
		scanf("%d", &x);
	}

	for (int i = 0; i < NUMBER; i++) {
		printf("%d: %d\n", i, cnt[i]);
	}
	return 0;
}
