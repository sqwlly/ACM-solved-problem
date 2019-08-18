#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
ll fib[55] = { 0,6,7 };
char ans1[] = "aCOFFEE";
char ans2[] = "bCHICKEN";
void solve(ll n, ll k) {
	ll start = 0;
	int fff=n;
	int num_out;//应该输出的字符
	num_out = (fib[n] - k >= 9 ? 10 : fib[n] - k + 1);
	while (n > 3) {
		//逆向fib工程
		if (start + fib[n - 2] > k) {
			n -= 2;
		}
		else {
			start += fib[n - 2];
			n--;
		}
	}
	//开始输出
	k -= start;
	printf("%lld %lld\n", k, n);
	if (n == 2) {
		int beif = 1;
		while (num_out--) {
			if (k == 0) { putchar('N'); k++; }
			else if (k <= 7) putchar(ans2[k++]);
			else putchar(ans1[beif++]);
			if (beif == 7) beif = 1;
		}
	}
	else {
		int init = k;
		if (k < 7) {
			while (num_out--) {
				if (k <= 6) putchar(ans1[k++]);
				else if (k - 7 <= 6) {
					assert(k - 6 >= 0 && k - 6 < 8);
					putchar(ans2[k - 6]); k++; }
				else {
					assert(k - 13 >= 0 && k - 13 < 8);
					putchar(ans2[k - 13]); k++;
				}
			}
		}
		else {
			while (num_out--) {
				if (k - 7 <= 6) { 
					assert(k - 6 >= 0 && k - 6 < 8);
					putchar(ans2[k - 6]); k++; }
				else {
					assert(k - 13 >= 0);
					putchar(ans1[k - 13]); k++;
				}
			}
		}

	}
	putchar('\n');
}
int main() {
	for (int i = 3; i <= 53; i++)
		fib[i] = fib[i - 1] + fib[i - 2];
	int t;
	scanf("%d", &t);
	//for (int i = 3; i <= 53; i++)
	//	printf("%d %lld\n",i, fib[i]);
	while (t--) {
		ll n, k;
		scanf("%lld %lld", &n, &k);
		if (n > 53) n = (n % 2 == 0 ? 52 : 53);
		solve(n, k);
	}
}
