/*************************************************************************
    > File Name: I.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年11月14日 星期四 16时35分18秒
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
constexpr int N = 2E5+10;
typedef long long LL;
#define P pair<int,int>
vector<P> v;
int sum[N],L[N],R[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n, LEN = 0;
	cin >> n;
	for(int i = 1,x,y; i <= n; ++i) {
		cin >> x >> y;
		y--;
		v.push_back(P(x,y));
		LEN = max(LEN, y + 1);
		L[i] = x, R[i] = y;
		sum[y + 1]--;
		sum[x]++;
	}
	sort(L + 1, L + 1 + n);
	sort(R + 1, R + 1 + n);
	P ans = P(0,0);
	for(int i = 1; i <= LEN; ++i) {
		sum[i] += sum[i - 1];
		ans.second = max(ans.second, sum[i]);
	}
	for(int i = 0; i < v.size(); ++i) {
		int l = lower_bound(R + 1, R + 1 + n, v[i].first) - R;
		int r = upper_bound(L + 1, L + 1 + n, v[i].second) - L;
		r--;
		ans.first = max(ans.first, n - (l - 1) - (n - r));
	}
	cout << ans.first << ' ' << ans.second << endl;
    return 0;
}
