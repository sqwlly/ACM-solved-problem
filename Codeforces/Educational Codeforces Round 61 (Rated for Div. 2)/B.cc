/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月05日 星期二 23时22分28秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
typedef long long LL;
const int N = 3E5+10;
int a[N],d[N];
LL sum[N];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,m;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	sort(a + 1, a + n +1, greater<int>());
	for(int i = 1; i <= n; ++i) {
		sum[i] = sum[i - 1] + a[i];
	}
	cin >> m;
	LL cost = 0;
	for(int i = 0; i < m; ++i) {
		cin >> d[i];
		cost = sum[d[i]] - a[d[i]] + (sum[n] - sum[d[i]]);
		cout << cost << endl;
	}
    return 0;
}
