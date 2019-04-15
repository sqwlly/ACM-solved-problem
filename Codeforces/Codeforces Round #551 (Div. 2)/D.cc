/*************************************************************************
    > File Name: D.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com
    > Created Time: 2019年04月15日 星期一 14时50分28秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 3E5+10;
vector<int> E[N];
int dp[N], a[N], leaf, n;

void dfs(int u)
{
	if(E[u].size() == 0) {
		dp[u] = 1;
		leaf++;
		return;
	}
	dp[u] = a[u] ? n : 0;
	for(const auto & v : E[u]) {
		dfs(v);
		if(a[u]) {
			dp[u] = min(dp[u],dp[v]);
		}else{
			dp[u] += dp[v];
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int x;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for(int i = 2; i <= n; ++i) {
		cin >> x;
		E[x].emplace_back(i);
	}
	dfs(1);
	cout << leaf + 1 - dp[1] << endl;
    return 0;
}

