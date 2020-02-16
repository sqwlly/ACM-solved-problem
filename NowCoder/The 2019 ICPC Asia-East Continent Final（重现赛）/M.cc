/*************************************************************************
    > File Name: M.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2020年01月14日 星期二 17时17分33秒
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
const int N = 1E5+10;
typedef long long LL;
LL a[N],b[N];
bool vis[N];

bool check(LL x,LL y)
{
	LL t = x;
	while(t <= y) {
		t *= x;
		if(t == y) return 1;
	}
	return 0;
}

LL gao(const vector<LL> &v)
{
	LL n = v.size();
	LL ret = 0, sum = 0;
	for(LL i = 0; i < (1 << n); ++i) {
		LL ans = 0;
		vector<LL> t;
		for(LL j = 0; j < n; ++j) {
			if((i >> j) & 1) {
				t.push_back(v[j]);
				ans += a[v[j]];
			}
		}
		for(LL j = 0; j < t.size(); ++j) {
			for(LL k = 0; k < t.size(); ++k) {
				if(t[j] > t[k] && check(t[k], t[j])) {
					ans -= b[t[j]];
				}
			}
		}
		ret = max(ans, ret);
	}
	return ret;
}

void solve(LL n)
{
	LL ans = a[1];
	for(LL i = 2; i <= n; ++i) {
		if(vis[i]) continue;
		LL t = i;
		vector<LL> v;
		v.push_back(t);
		for(LL k = 2; i * i <= n; ++k) {
			t *= i;
			if(t > n) break;
			vis[t] = 1;
			v.push_back(t);
		}
		if(i * i <= n) {
			ans += gao(v);
		}else{
			ans += a[i];
		}
	}
	cout << ans << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	LL n;
	cin >> n;
	for(LL i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	for(LL i = 1; i <= n; ++i) {
		cin >> b[i];
	}
	solve(n);
    return 0;
}
