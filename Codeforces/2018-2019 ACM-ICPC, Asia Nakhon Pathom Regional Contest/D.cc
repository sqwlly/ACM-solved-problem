/*************************************************************************
    > File Name: D.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年08月25日 星期日 09时23分53秒
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
const int N = 5010;
int h[N],dp[N];

pair<int,int> p[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,x,w;
	cin >> n >> w;
	for(int i = 1; i <= n; ++i) {
		cin >> x;
		p[i] = make_pair(x,i);
	}
	sort(p + 1, p + n + 1);
	int cnt = 0, last = 1, ans = 0;
	dp[1] = 0;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j < i; ++j) {
			if(abs(p[i].second - p[j].second) <= w && p[i].second != p[j].second && p[i].first > p[j].first) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		ans = max(ans , dp[i]);
	}
	cout << ans << endl;
    return 0;
}
