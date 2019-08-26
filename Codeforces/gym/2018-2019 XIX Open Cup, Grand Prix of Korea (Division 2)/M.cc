/*************************************************************************
    > File Name: M.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年08月24日 星期六 09时34分28秒
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
const int MAXN = 1024;
pair<int,int> p[MAXN];
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int N,K,A,s,t;
	cin >> N >> K >> A;
	for(int i = 0; i < N; ++i) {
		cin >> t >> s;
		p[i] = make_pair(t,s);
	}
	int ans = INT_MAX;
	for(int i = 0; i < N; ++i) {
		int res = p[i].first * A;
		int cnt = ceil(1.0 * K / res);
		int ret = cnt * res - K;
	//	dbg(res,cnt,ret);
		int cst = cnt * (p[i].first + p[i].second) - p[i].second - ret / A;
		ans = min(ans, cst);
	}
	cout << ans << endl;
    return 0;
}
