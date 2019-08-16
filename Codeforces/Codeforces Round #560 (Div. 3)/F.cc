/*************************************************************************
    > File Name: F.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年08月13日 星期二 19时47分00秒
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
vector<pair<int,int>> v;
vector<int> a,foo;
int n,m,dead[N];
LL sum;
bool check(LL x)
{
	LL cst = 0;
	foo = a;
	for(int i = 1; i <= n; ++i) dead[i] = 0;
	for(int i = 1; i <= m; ++i) {
		if(x >= v[i].first) {
			dead[v[i].second] = max(dead[v[i].second], v[i].first);
		}
	}
	int t = 0, cnt = 0;
	for(int i = 1; i <= m; ++i) {
		if(x >= v[i].first) {
			cst += v[i].first - v[i - 1].first;
			if(v[i].first == dead[v[i].second]) {
				t = min(cst, foo[v[i].second] * 1LL);
				cnt += t;
				foo[v[i].second] -= t;
				cst -= t;
			}
		}
	}
	return sum - cnt <= x;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int d,t,c;
	cin >> n >> m;
	a.emplace_back(0);
	for(int i = 1; i <= n; ++i) {
		cin >> c;
		sum += c;
		a.emplace_back(c);
	}
	sum *= 2;
	v.emplace_back(make_pair(0,0));
	for(int i = 0; i < m; ++i) {
		cin >> d >> t;
		v.emplace_back(make_pair(d,t));
	}
	sort(v.begin() + 1, v.end());
	LL l = 1, r = LLONG_MAX >> 1, ans = LLONG_MAX;
	while(l <= r) {
		LL mid = l + r >> 1;
		if(check(mid)) {
			ans = mid;
			r = mid - 1;
		}else{
			l = mid + 1;
		}
	}
	cout << ans << endl;
    return 0;
}
