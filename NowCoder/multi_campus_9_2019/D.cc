/*************************************************************************
    > File Name: D.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年08月15日 星期四 12时45分17秒
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
const int N = 40;
LL a[N],ret, ans = 0, n;
map<LL,LL> dp;
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> ret;
	for(LL i = 0; i < n; ++i) {
		cin >> a[i];
	}
	vector<LL> u,v;
	for(LL i = 0; i < (1 << (n / 2)); ++i) {
		pair<LL,LL> p = make_pair(0,0);
		for(LL j = 0; j < n / 2; ++j) {
			if(i & (1 << j)) {
				p.first |= 1 << j;
				p.second += a[j];
			}
		}
		dp[p.second] = p.first;
		u.emplace_back(p.second);
	}
	sort(u.begin(),u.end());
	for(LL i = 0; i < (1 << (n - n / 2)); ++i) {
		pair<LL,LL> p = make_pair(0,0);
		for(LL j = 0; j < (n - n / 2); ++j) {
			if(i & (1 << j)) {
				p.first |= 1 << j;
				p.second += a[j + n / 2];
			}
		}
		if(binary_search(u.begin(),u.end(),ret - p.second)) {
			LL res = (*lower_bound(u.begin(),u.end(),ret - p.second));
			LL S1 = dp[res];
			for(LL j = 0; j < n / 2; ++j) {
				cout << ((S1 >> j) & 1);
			}
			for(LL j = 0; j < n - n / 2; ++j) {
				cout << ((p.first >> j) & 1);
			}
			break;
		}
	}
    return 0;
}
