/*************************************************************************
    > File Name: D_.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2020年02月19日 星期三 11时37分32秒
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
int a[N],p[N],s[N],suf[N],dp[N][20];
int get(int l,int r)
{
	int k = log2(r - l + 1);
	return max(dp[l][k], dp[r - (1 << k) + 1][k]);
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,m,T;
	for(cin >> T; T--;) {
		cin >> n;
		for(int i = 1; i <= n; ++i) {
			cin >> a[i];
			dp[i][0] = a[i];
			suf[i] = 0;
		}
		for(int j = 1; j < 20; ++j) {
			for(int i = 1; i + (1 << j) - 1 <= n; ++i) {
				dp[i][j] = max(dp[i][j - 1], dp[i + (1 << j - 1)][j - 1]);
			}
		}
		cin >> m;
		for(int i = 1; i <= m; ++i) {
			cin >> p[i] >> s[i];
			suf[s[i]] = max(suf[s[i]], p[i]);
		}
		for(int i = n - 1; i >= 0; --i) {
			suf[i] = max(suf[i], suf[i + 1]);
		}
		if(suf[1] < get(1, n)) {
			cout << -1 << '\n';
			continue;
		}
		int p = 1, ret = 0;
		while(p <= n) {
			int l = p, r = n;
			while(l < r) {
				int mid = (l + r) / 2;
				if(get(p, mid) <= suf[mid - p + 1]) {
					l = mid + 1;
				}else{
					r = mid;
				}
			}
			if(get(p, l) > suf[l - p + 1]) l--;
			ret++;
			p = l + 1;
		}
		cout << ret << '\n';
	}
    return 0;
}
