/*************************************************************************
    > File Name: I1.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年01月25日 星期五 00时45分18秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
struct node{
	int a,b;
	long long c;
	bool operator < (const node & u) const {
		return c > u.c;
	}
}f[1010];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> f[i].a >> f[i].b;
	}
	long long ans = 0, sum = 0;
	for(int i = 1; i <= n; ++i) {
		sum = 0;
		for(int j = 1; j <= n; ++j) {
			f[j].c = f[j].a - f[j].b * i;
		}
		sort(f + 1, f + n + 1);
		for(int j = 1; j <= i; ++j) {
			sum += f[j].a;
		}
		for(int j = i + 1; j <= n; ++j) {
			sum += f[j].b * i;
		}
		ans = max(ans, sum);
	}
	cout << ans << endl;
    return 0;
}
