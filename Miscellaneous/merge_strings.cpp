// 编写一个函数void str_bin(char str1[], char str2[])， str1、str2是两个有序字符串（其中字符按ASCII码从小到大排序），将str2合并到字符串str1中，要求合并后的字符串仍是有序的，允许字符重复。在main函数中测试该函数：从键盘输入两个有序字符串，然后调用该函数，最后输出合并后的结果。

#include <bits/stdc++.h>

using namespace std;

void str_bin(char str1[], char str2[]);

int main(int argc, char **argv) {
	char a[101], b[101];

	scanf("%s", a);
	scanf("%s", b);

	str_bin(a, b);

	puts(a);

	return 0;
}

void str_bin(char str1[], char str2[]) {
	char temp[202];
	int i = 0, j = 0, k = 0;
	while (str1[i] != '\0' && str2[j] != '\0') {
		if (str1[i] < str2[j]) {
			temp[k++] = str1[i++];
		}
		else if (str1[i] > str2[j]) {
			temp[k++] = str2[j++];
		}
		else {
			temp[k++] = str1[i++];
			temp[k++] = str2[j++];
		}
	}

	temp[k] = '\0';

	if (str1[i] != '\0') {
		strcat(temp, str1 + i);
	}
	else if (str2[j] != '\0') {
		strcat(temp, str2 + j);
	}

	strcpy(str1, temp);
}
