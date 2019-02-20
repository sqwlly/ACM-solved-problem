/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年02月19日 星期二 22时50分43秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
int a[10010];
long long sum[10010][2];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		sum[i][i & 1] = sum[i - 1][i & 1] + a[i];
	}
	int cnt = 0;
	for(int i = 1; i <= n; ++i) {
		long long A = sum[n][!(i & 1)] - sum[i - 1][!(i & 1)];
		long long B = sum[n][i & 1] - sum[i - 1][(i & 1)];
		if(A == B) cnt++;
	}
	cout << cnt << endl;
    return 0;
}
