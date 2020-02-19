/*************************************************************************
    > File Name: cf165C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2020年02月18日 星期二 11时11分18秒
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
typedef long long LL;
const int N = 1E6+10;
int dp[N], k;
string s;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	cin >> k >> s;
	LL ans = 0;
	int d = 0;
	dp[0] = 1;
	for(int i = 0; i < s.size(); ++i) {
		if(s[i] == '1') {
			d++;
		}
		if(d >= k) ans += dp[d - k];
		dp[d]++;
	}
	cout << ans << '\n';
    return 0;
}
