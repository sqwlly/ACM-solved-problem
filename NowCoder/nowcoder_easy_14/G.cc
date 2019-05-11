/*************************************************************************
    > File Name: G.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年05月11日 星期六 19时51分12秒
 ************************************************************************/

#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
const int N = 2E6+10;
LL a[N],b[N];

void solve(int n)
{
	for(int i = 1; i <= n; ++i) {
		for(int j = i; j <= n; j += i) {
			b[j] += a[i];
		}
	}
}

int main() {
	int n,a1,m;
	cin >> n >> a1 >> m;
	a[1] = a1;
	for(int i = 2; i <= n; ++i) {
		a[i] = (a[i - 1] + 7 * i) % m;
	}
	solve(n);
	LL ans = 0;
	for(int i = 1; i <= n; ++i) {
		ans ^= b[i];
	}
	cout << ans << endl;
	return 0;
}
