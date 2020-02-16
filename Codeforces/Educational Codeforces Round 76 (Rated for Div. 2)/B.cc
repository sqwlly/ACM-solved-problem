/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年11月16日 星期六 10时08分33秒
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
bool ok(LL x,LL y)
{
	if(x >= y) return 1;
	if(x & 1) {
		x--;
	}
	map<int,bool> vis;
	while(x / 2 * 3 < y) {
		x = x / 2 * 3;
		if(vis[x]) return 0;
		vis[x] = 1;
		if(x >= y) return 1;
		if(x & 1) x--;
	}
	if(x / 2 * 3 >= y) return 1;
	return 0;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int T,x,y;
	cin >> T;
	while(T--) {
		cin >> x >> y;
		cout << (ok(x,y) ? "YES" : "NO") << '\n';
	}
    return 0;
}
