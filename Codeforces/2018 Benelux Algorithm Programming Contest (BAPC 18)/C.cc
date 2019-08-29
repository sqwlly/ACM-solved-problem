#include<stdio.h>
int ans = 0x3f3f3f;
int surface(int x, int y, int z) {
	return 2 * (x * y + x * z + y * z);
}
int min(int a, int b) {
	return a < b ? a : b;
}
int main() {
	int v;
	scanf("%d", &v);
	for (int i = 1; i * i <= v; i++) {
		if (v % i == 0) {
			for (int j = 1; j * j <= v / i; j++){
				if ((v / i) % j == 0) {
					ans = min(ans, surface(i, j, v / i / j));
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
