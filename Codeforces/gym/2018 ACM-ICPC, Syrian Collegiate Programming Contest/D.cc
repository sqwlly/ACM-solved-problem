/*************************************************************************
    > File Name: D.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年09月10日 星期二 09时41分34秒
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
const int N = 1 << 9;
int ball[N],dp[N][N],a[N],r,c;
string s[N];

int dfs(int x,int y)
{
	if(y > c || y < 1) return 0;
	if(dp[x][y] != -1) return dp[x][y];
	if(x > r) {
		return a[y];	
	}
	if(s[x][y] == '.') {
		return dfs(x + 1, y);
	}else{
		int ret = 0;
		ret = max(ret, dfs(x + 1, y + 1));
		ret = max(ret, dfs(x + 1, y - 1));
		ret = max(ret, dfs(x + 1, y));
		return dp[x][y] = ret;
	}
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int T;
	//freopen("balls.in","r",stdin);
	cin >> T;
	while(T--) {
		cin >> r >> c;
		for(int i = 0; i <= r + 1; ++i) {
			for(int j = 0; j <= c + 1; ++j) {
				dp[i][j] = -1;
			}
		}
		for(int i = 1; i <= c; ++i) {
			cin >> ball[i];
		}
		for(int i = 1; i <= r; ++i) {
			cin >> s[i];
			s[i] = '.' + s[i];
		}
		for(int i = 1; i <= c; ++i) {
			cin >> a[i];
		}
		LL ans = 0;
		for(int i = 1; i <= c; ++i) {
			ans += dfs(1,i) * 1LL * ball[i];
		}
		cout << ans << '\n';
	}
    return 0;
}
