/*************************************************************************
    > File Name: cf706_.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年10月02日 星期三 19时29分34秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(args...)                                   \
    do{                                                \
	        cout << "\033[32;1m" << #args << " -> ";   \
         err(args);                                    \
      } while(0)                                       
#else
#define dbg(...)
#endif
void err()
{
    cout << "\033[39;0m" << endl;
}
template <template <typename...> class T, typename t, typename... Args>
void err(T<t> a, Args... args)
{
    for (auto x : a) cout << x << ' ';
    err(args...);
}
template <typename T, typename... Args>
void err(T a, Args... args)
{
    cout << a << ' ';
    err(args...);
}
/****************************************************************************************************/
constexpr int N = 1E5+10;
typedef long long LL;
int cst[N];
LL dp[N][2];
string s[N],rev[N];
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) cin >> cst[i];
	for(int i = 1; i <= n; ++i) {
		cin >> rev[i];
		s[i] = rev[i];
		reverse(rev[i].begin(),rev[i].end());
	}
	for(int i = 0; i <= n; ++i) {
		dp[i][0] = dp[i][1] = LLONG_MAX / 2;
	}
	dp[0][0] = dp[0][1] = 0;
	//dp[1][1] = cst[1];
	LL ans = LLONG_MAX;
	bool ok;
	for(int i = 1; i <= n; ++i) {
		ok = 0;
		if(s[i] >= s[i - 1]) {
			ok = 1;
			dp[i][0] = min(dp[i][0], dp[i - 1][0]);
		}
		if(s[i] >= rev[i - 1]) {
			ok = 1;
			dp[i][0] = min(dp[i][0], dp[i - 1][1]);
		}
		if(rev[i] >= s[i - 1]) {
			ok = 1;
			dp[i][1] = min(dp[i][1], dp[i - 1][0] + cst[i]);
		}
		if(rev[i] >= rev[i - 1]) {
			ok = 1;
			dp[i][1] = min(dp[i][1], dp[i - 1][1] + cst[i]);
		}
		//dbg(i,dp[i][0], dp[i][1]);
		if(ok == 0) return cout << -1 << '\n',0;
	}
	if(dp[n][1] == LLONG_MAX / 2 && dp[n][0] == LLONG_MAX / 2) return cout << -1 << '\n',0;
	cout << min(dp[n][0], dp[n][1]) << endl;
    return 0;
}
