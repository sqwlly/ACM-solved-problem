/*************************************************************************
    > File Name: hdu1024.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月19日 星期二 21时24分45秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
typedef long long LL;
using namespace std;
const int N = 1E6+10;
int a[N];
LL dp[N], MAX[N];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,m;
	cin >> n >> m;
	LL ret = 0;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for(int i = 0; i < m; ++i) {
		LL MIN = -LLONG_MAX >> 1;
		for(int j = 0; j < n; ++j) {
			dp[j] = max(dp[j - 1],)
		}
	}
    return 0;
}
