/*************************************************************************
    > File Name: F.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月06日 星期三 23时28分56秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
int dp[600][600],n;
string s;
int dfs(int l,int r)
{
	if(r < l) return 0;
	if(dp[l][r] != - 1) return dp[l][r];
	int min1 = INT_MAX;
	for(int i = l; i <= r; ++i) {
		int ret = dfs(l, i - 1) + dfs(i + 1, r);
		if(s[i] != s[l - 1] && s[i] != s[r + 1]) ret++;
		min1 = min(min1, ret);
	}
	return dp[l][r] = min1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	memset(dp, -1, sizeof dp);
	cin >> n >> s;
	s = '\0' + s + '\0';
	cout << dfs(1,n) << endl;
    return 0;
}
