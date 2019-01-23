/*************************************************************************
    > File Name: I.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年01月23日 星期三 14时19分38秒
 ************************************************************************/
#include<bits/stdc++.h>

using namespace std;

struct node{
	int a, b;
	bool operator < (const node & u) const{
		if(b == u.b) {
			return a > u.a;
		}
		return b < u.b;
	}
}f[1001];
long long dp[1010][1010];

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
	sort(f + 1, f + n + 1);
	//20
	//21 + 2 + 20 + 2 = 45
	//15 + 45 + 10
	long long now = 0;
	for(int i = 1; i <= n; ++i) {
//		dp[i][i] = dp[i - 1][i - 1] + f[i].a;
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= i; ++j) {
			if(dp[i - 1][j - 1] == 0 && j - 1 != 0) continue;
			long long A = dp[i - 1][j - 1] + f[j].a;
			long long B = dp[i - 1][j - 1] + f[j].b * (i - 1);
			if(A > B)
				dp[i][j] = A;
			else
				dp[i][j - 1] = B;
		//	dp[i][j] = max(dp[i - 1][j - 1] + f[j].a, dp[i - 1][j] + f[j].b * (i - 1));
		}
	}
	for(int i = 0; i <= n; ++i) {
		now = max(now , dp[n][i]);
	}
	cout << now << endl;
    return 0;
}
