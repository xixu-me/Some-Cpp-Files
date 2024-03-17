// 你通过观察发现他房间内有 n 个可用于制成绳子的物品，第 i 个的长度为 ai。当你使用第 i 个物品制作绳子时，其右侧的 k 个物品（不含第i个物品）就无法再被用于制作绳子 。最终，小竹用选择的物品制成绳子，绳子的长度是所选择物品的长度之和。小竹想知道,他能制作的绳子长度最长为多少？

#include <bits/stdc++.h>

using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}

int main(int argc, char **argv) {
	int n, k;
	scanf("%d %d", &n, &k);
	int *temp, *ans;
	ans = (int *)malloc(sizeof(int) * (n + 1));
	temp = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++)
		scanf("%d", &temp[i]);
	for (int i = 1; i <= n; i++) {
		if (i == 1)
			ans[i] = temp[i - 1];
		else if (i <= k + 1) {
			ans[i] = max(ans[i - 1], temp[i - 1]);
		}
		else {
			ans[i] = max(ans[i - 1], ans[i - k - 1] + temp[i - 1]);
		}
	}

	printf("%d", ans[n]);
	return 0;
}