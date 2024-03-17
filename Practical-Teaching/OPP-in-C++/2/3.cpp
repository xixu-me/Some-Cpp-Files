// 模仿二维数组，使用引用调用和引用返回，把函数代码补完整。

#include <bits/stdc++.h>

using namespace std;

struct twodim {
	int r;
	int c;
	float *a;
};
void get_twodim(twodim &s, int row, int col) {
	// 初始化数组
	s.r = row;
	s.c = col;
	s.a = new float[s.r * s.c];
}
float &val(twodim &s, int i, int j) {
	// 返回i行j列的值
	return s.a[i * s.c + j];
}
void free_twodim(twodim &s) {
	// 释放数组空间
	delete[] s.a;
}
int main() {
	struct twodim s;
	int i, j;
	get_twodim(s, 3, 4);

	for (i = 0; i < 3; i++)
		for (j = 0; j < 4; j++)
			val(s, i, j) = i + j;

	for (i = 0; i < 3; i++) {
		for (j = 0; j < 4; j++)
			cout << setw(5) << val(s, i, j);

		cout << endl;
	}
	free_twodim(s);

	return 0;
}