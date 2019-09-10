/*************************************************************************
    > File Name: H.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年09月10日 星期二 10时46分18秒
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
const int N = 2E5+10;
typedef long long LL;
int deg[N],u[N],v[N];
int dis[N];
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	freopen("bugged.in","r",stdin);
	int T,n,m;
	cin >> T;
	while(T--) {
		cin >> n >> m;
		for(int i = 0; i <= n; ++i) {
			deg[i] = 0;
		}
		for(int i = 1; i <= n; ++i) {
			cin >> dis[i];
		}
		for(int i = 0; i < m; ++i) {
			cin >> u[i] >> v[i];
			deg[u[i]]++;
			deg[v[i]]--;
		}
		bool ok = 1;
		for(int i = 1; i <= n; ++i) {
			if(deg[i]) {
				ok = 0;
				break;
			} 
		}
		if(!ok) cout << -1 << '\n';
		else{
			LL ans = 0;
			for(int i = 0; i < m; ++i) {
				ans += abs(dis[u[i]] - dis[v[i]]);
			}
			cout << ans << '\n';
		}
	}
    return 0;
}
