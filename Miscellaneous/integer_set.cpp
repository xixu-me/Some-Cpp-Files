#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int a;
	int i, j, k;
	int cnt = 0;

	scanf("%d", &a);

	i = a;
	while (i <= a + 3) {
		j = a;
		while (j <= a + 3) {
			k = a;
			while (k <= a + 3) {
				if (i != j) {
					if (i != k) {
						if (j != k) {
							printf("%d%d%d", i, j, k);
							cnt++;
							if (cnt == 6) {
								printf("\n");
								cnt = 0;
							}
							else {
								printf(" ");
							}
						}
					}
				}
				k++;
			}
			j++;
		}
		i++;
	}

	return 0;
}
