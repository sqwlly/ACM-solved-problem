/*************************************************************************
    > File Name: J.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com
    > Created Time: 2019年01月20日 星期日 13时50分56秒
 ************************************************************************/
#include<bits/stdc++.h>
#define P pair<int,int>
using namespace std;
typedef long long LL;
const int N = 1001;
multiset<P> g[N], v;
bool vis[N];
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
#endif
    int n, m, a, c;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> a >> c;
        v.insert(P(a,i));
		g[c].insert(P(a,i));
    }
	LL ans = 1e18;
	for(int k = 1; k <= m; ++k) {
		memset(vis, 0, sizeof vis);
		LL ret = 0;
		int sum = 0;
		for(int i = 1; i <= n; ++i) {
			int get = 0;
			if(g[i].size() >= k) {
				for(auto t : g[i]) {
					ret += t.first; 
					vis[t.second] = 1;
					get++;
					if(get > g[i].size() - k) break;
				}
			}
			sum += get;
		}
		for(auto t : v) {
			if(sum >= k) break;
			if(vis[t.second] == 0) ret += t.first, sum++;
		}
		ans = min(ans, ret);
	}
    cout << ans << endl;
    return 0;
}
