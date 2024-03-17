#include <stdio.h>

// 定义多项式的项
typedef struct
{
	int coefficient; // 系数
	int exponent;	 // 指数
} Term;

// 函数声明
void addPolynomials(Term poly1[], int n1, Term poly2[], int n2, Term result[], int *nResult);

int main() {
	int n1, n2;

	// 输入第一个多项式的项数
	printf("第一个多项式\n项数：");
	scanf("%d", &n1);

	// 输入第一个多项式的各项系数和指数
	Term poly1[n1];
	for (int i = 0; i < n1; i++) {
		printf("第%d项系数和指数：", i + 1);
		scanf("%d %d", &poly1[i].coefficient, &poly1[i].exponent);
	}

	// 输入第二个多项式的项数
	printf("\n第二个多项式\n项数：");
	scanf("%d", &n2);

	// 输入第二个多项式的各项系数和指数
	Term poly2[n2];
	for (int i = 0; i < n2; i++) {
		printf("第%d项系数和指数：", i + 1);
		scanf("%d %d", &poly2[i].coefficient, &poly2[i].exponent);
	}

	// 计算两个多项式的和
	int nResult = n1 + n2;
	Term result[nResult];
	addPolynomials(poly1, n1, poly2, n2, result, &nResult);

	// 输出结果
	printf("\n和多项式的各项为：\n");
	for (int i = 0; i < nResult; i++) {
		printf("第%d项，系数：%d，指数：%d\n", i + 1, result[i].coefficient, result[i].exponent);
	}

	return 0;
}

// 实现多项式相加的函数
void addPolynomials(Term poly1[], int n1, Term poly2[], int n2, Term result[], int *nResult) {
	int i = 0, j = 0, k = 0;

	// 循环遍历两个多项式的项
	while (i < n1 && j < n2) {
		// 比较当前项的指数大小
		if (poly1[i].exponent > poly2[j].exponent) {
			result[k++] = poly1[i++];
		}
		else if (poly1[i].exponent < poly2[j].exponent) {
			result[k++] = poly2[j++];
		}
		else {
			// 指数相等时，系数相加
			result[k].exponent = poly1[i].exponent;
			result[k++].coefficient = poly1[i++].coefficient + poly2[j++].coefficient;
		}
	}

	// 处理多项式1剩余的项
	while (i < n1) {
		result[k++] = poly1[i++];
	}

	// 处理多项式2剩余的项
	while (j < n2) {
		result[k++] = poly2[j++];
	}

	// 更新结果多项式的项数
	*nResult = k;
}
