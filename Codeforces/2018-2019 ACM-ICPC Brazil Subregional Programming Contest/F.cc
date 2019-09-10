/*************************************************************************
  > File Name: F.cc
  > Author: sqwlly
  > Mail: sqw.lucky@gmail.com 
  > Created Time: 2019年08月29日 星期四 12时30分35秒
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
const int N = 1024, M = 1E5+10;
struct node{
	int l,r,w,id;
	bool operator < (const node &u) const{
		if(r == u.r) return l < u.l;
		return r < u.r;
	}
};

vector<node> g;
vector<int> foo;
int dp[N][1 << 11], Max[1 << 11][M];
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	int n,k,l,r,w;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> k;
		for(int j = 0; j < k; ++j) {
			cin >> l >> r >> w;
			g.push_back(node{l,r,w,i});
			foo.emplace_back(l);
			foo.emplace_back(r);
		}
	}
	sort(g.begin(), g.end());
	sort(foo.begin(), foo.end());
	foo.resize(distance(foo.begin(),unique(foo.begin(),foo.end())));
	int ic = 1, ans = 0;
	for(int k = 0; k < g.size(); ++k) {
		node i = g[k];
		i.l = distance(foo.begin(),lower_bound(foo.begin(),foo.end(),i.l));
		i.r = distance(foo.begin(),lower_bound(foo.begin(),foo.end(),i.r));
		while(ic <= i.l) {
			for(int j = 1; j < (1 << n); ++j) {
				Max[j][ic] = max(Max[j][ic - 1],Max[j][ic]);	
			}
			ic++;
		}
		int s = i.id, x = i.l, y = i.r, w = i.w;
		dp[k][1 << s] = w;
		Max[1 << s][y] = max(Max[1 << s][y], w);
		for(int j = 1; j < (1 << n); ++j) {
			if(Max[j][x]) {
				dp[k][j | 1 << s] = max(dp[k][j | 1 << s], Max[j][x] + w);
			}
		
		}
		for(int j = 1; j < (1 << n); ++j) {
			if(dp[k][j])
				Max[j][y] = max(Max[j][y],dp[k][j]);
		}
		ans = max(dp[k][(1 << n) - 1], ans);
	}
	if(ans == 0) ans = -1;
	cout << ans << '\n';
	return 0;
}
