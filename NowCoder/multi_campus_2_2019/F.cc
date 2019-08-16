/*************************************************************************
    > File Name: F.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年07月24日 星期三 21时51分05秒
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
LL ans;
int v[40][40],n;
bool color[20];
void dfs(int cur,LL res,int S,int pre)
{
	if(cur == n) {
		ans = max(res, ans);
		return;
	}
	if(n + n - pre - 1 + cur < n) return;
	for(int nxt = pre + 1; nxt < n + n; ++nxt) {
		LL ret = res;
		for(int i = 0; i < n + n; ++i) {
			if(S & (1 << i)) {
				ret -= v[nxt][i];
			}else{
				ret += v[nxt][i];
			}
		}
		dfs(cur + 1, ret, S | 1 << nxt, nxt);
	}
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	LL cst;
	for(int i = 0; i < n + n; ++i) {
		for(int j = 0; j < n + n; ++j) {
			cin >> v[i][j];
		}
		cst += v[0][i];
	}
	dfs(1, cst, 1 << 0, 0);
	cout << ans << endl;
    return 0;
}
