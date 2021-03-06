/*************************************************************************
    > File Name: E.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年09月16日 星期一 12时26分17秒
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
const int N = 4E5+10;
typedef long long LL;
LL a[N],cnt[N], cst[21][21],dp[1 << 21];
vector<int> pos[21];
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		pos[a[i]].emplace_back(i);
	}
	for(int i = 1; i <= 20; ++i) {
		for(int j = 1; j <= 20; ++j) {
			if(i == j) continue;
			for(int k = 0; k < pos[i].size(); ++k) {
				if(pos[j].size() == 0 || pos[j][0] > pos[i][k]) continue;
				cst[i][j] += lower_bound(pos[j].begin(), pos[j].end(), pos[i][k]) - pos[j].begin();
			}
		}
	}
	LL S = 1 << 20, c = 0;
	for(int i = 0; i < S; ++i) dp[i] = LLONG_MAX >> 1;
	dp[0] = 0;
	for(int s = 0; s < S; ++s) {
		for(int i = 0; i < 20; ++i) {
			if(!((s >> i) & 1)) {
				c = 0;
				for(int j = 0; j < 20; ++j) {
					if((s >> j) & 1) {
						c += cst[i + 1][j + 1];			
					}
				}
				dp[s | 1 << i] = min(dp[s | 1 << i], dp[s] + c);
			}
		}
	}
	cout << dp[S - 1] << endl;
    return 0;
}
