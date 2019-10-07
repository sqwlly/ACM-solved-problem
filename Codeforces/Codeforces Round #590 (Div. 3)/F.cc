/*************************************************************************
    > File Name: F.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年10月04日 星期五 16时10分33秒
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

string s;

int dp[1 << 20];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	cin >> s;
	int n = s.size();
	for(int i = 0; i < n; ++i) {
		int used = 0;
		for(int j = i; j < n && j - i < 20; ++j) {
			int c = s[j] - 'a';
			if((used >> c) & 1) break;
			used |= 1 << c;
			dp[used] = j - i + 1;
		}
	}
	for(int i = 1; i < 1 << 20; ++i) {
		for(int j = 0; j < 20; ++j) {
			if(!((i >> j) & 1)) {
				dp[i | 1 << j] = max(dp[i | 1 << j], dp[i]);
		//		dp[i] = max(dp[i], dp[i ^ (1 << j)]);
			}
		}
	}
	
	int S = 1 << 20, ans = dp[S - 1];
	for(int i = 1; i < 1 << 20; ++i) {
		int mask = i ^ (S - 1);
		ans = max(ans, dp[i] + dp[mask]);
	}
	cout << ans << '\n';
    return 0;
}
