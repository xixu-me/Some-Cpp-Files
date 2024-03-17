#include <iostream>

using namespace std;

int main(void) {
	int x;
	printf("һǸ");
	scanf("%d", &x);

	int o, f, t, tt, ft, h;

	for (o = 0; o <= x; o++) {
		for (f = 0; f <= x / 5; f++) {
			for (t = 0; t <= x / 10; t++) {
				for (tt = 0; tt <= x / 20; tt++) {
					for (ft = 0; ft <= x / 50; ft++) {
						for (h = 0; h <= x / 100; h++) {
							if (o * 1 + f * 5 + t * 10 + tt * 20 + ft * 50 + h * 100 == x) {
								printf("Խ %d һԪ%d Ԫ%d ʮԪ%d ŶʮԪ%d ʮԪ %d һԪõ %d Ԫ\n", o, f, t, tt, ft, h, x);
								goto out;
							}
						}
					}
				}
			}
		}
	}
out:

	return 0;
}