/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年07月25日 星期四 12时10分59秒
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
const int N = 1E5+10;
int one[N],zero[N], lastOne[N], lastZero[N], dp[N];
map<int,int> m;
void solve(string s,int n)
{
	int cnt = 0;
	m[0] = 0;
	for(int i = 1; i <= n; ++i) {
		if(s[i - 1] == '1') {
			cnt++;
			dp[i] = dp[i - 1] + 1;			
		}else{
			dp[i] = dp[i - 1] - 1;
		}
//		cout << dp[i] << ' ';
	}
//	cout << endl;
	int ans = 0, cur = 0, ret = 0;
	for(int i = 1; i <= n; ++i) {
		if(m.count(dp[i]) == 0) {
			m[dp[i]] = i;
		}else{
			ans = max(ans, i - m[dp[i]]);
		}
	}
	cout << ans << ' ' << min(cnt, n - cnt) * 2 << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	solve(s,n);
	return 0;
}
