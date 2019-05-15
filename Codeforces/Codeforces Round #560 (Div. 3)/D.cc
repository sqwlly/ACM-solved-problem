/*************************************************************************
    > File Name: D.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年05月14日 星期二 23时34分36秒
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
const int N = 2E6+10;
typedef long long LL;
LL xx[N],a[1000];
map<LL,bool> vis;
vector<LL> v;
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int T,n;
	for(int i = 2; i < N; ++i) {
		xx[i] = 1LL * i * i;
	}
	cin >> T;
	while(T--) {
		v.clear();
		cin >> n;
		vis.clear();
		for(int i = 0; i < n; ++i) {
			cin >> a[i];
			v.emplace_back(a[i]);
		}
		int ok = 1;
		LL lcm = a[0];
		if(n == 1) {
			lcm = xx[a[0]];
		}
		for(int i = 1; i < n; ++i) {
			lcm = a[i] / __gcd(a[i],lcm) * lcm;
		}
		sort(v.begin(),v.end());
		LL t = lcm;
		if(v[n - 1] == lcm) {
			t *= v[0];
		}
		if(t > 1e13 ||  t < 0) {
			cout << -1 << endl;
			continue;
		}
		vector<int> Cc;
		for(LL j = 2; j * j <= t; ++j) {
			assert(j * j > 0);
			if(j * j == t) {
				Cc.emplace_back(j);
			}else if(t % j == 0) {
				Cc.emplace_back(j);
				Cc.emplace_back(t / j);
			}
		}
		if(Cc.size() != v.size()) {
			cout << -1 << endl;
		}else{
			cout << t << endl;
		}
	}
    return 0;
}
