#include <bits/stdc++.h>

using namespace std;

int main(int argc, char **argv) {
	char a[5][999];

	for (int i = 0; i < 5; i++) {
		scanf("%s", a[i]);
	}

	for (int i = 0; i < 4; i++) {
		char temp[999];
		for (int j = 0; j < 4 - i; j++) {
			if (strcmp(a[j], a[j + 1]) > 0) {
				strcpy(temp, a[j]);
				strcpy(a[j], a[j + 1]);
				strcpy(a[j + 1], temp);
			}
		}
	}

	for (int i = 0; i < 5; i++) {
		printf("%s\n", a[i]);
	}

	return 0;
}