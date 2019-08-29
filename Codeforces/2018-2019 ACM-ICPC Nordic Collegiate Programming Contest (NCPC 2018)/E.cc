/*************************************************************************
    > File Name: E.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年08月27日 星期二 12时52分35秒
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
//  2/3  1/2
//
int a[10],b[10],n,m;
double ans = 1;
void dfs(int d)
{
	bool dead = 1;
	for(int i = 0; i < m; ++i) {
		if(b[i] > 0) dead = 0;
	}
	if(dead || d == 0) return;
	int cnt = 0, tot = 0;
	for(int i = 0; i < n; ++i) {
		if(a[i]) tot++;
	}
	for(int i = 0; i < m; ++i) {
		if(b[i]) tot++;
	}
	for(int i = 0; i < n; ++i) {
		if(a[i] > 0) {
			a[i]--;
			dfs(d - 1);
		}
	}
	for(int i = 0; i < m; ++i) {
		if(b[i] > 0) {
			b[i]--;
			dfs(d - 1);
		}
	}
	for(int i = 0; i < m; ++i) {
		if(b[i] <= 0) {
			cnt++;
		}
	}
	dbg(cnt,tot);
	ans *= 1.0 * cnt / tot;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int d;
	cin >> n >> m >> d;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for(int i = 0; i < m; ++i) {
		cin >> b[i];
	}
	dfs(d);
	cout << ans << endl;
    return 0;
}
