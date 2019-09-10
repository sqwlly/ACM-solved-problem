#include<stdio.h>
int main() {
	int T, ans = 0;
	scanf("%d", &T);
	while (T--) {
		int temp;
		scanf("%d", &temp);
		if (temp != 1) ans++;
	}
	printf("%d", ans);
	return 0;
}
