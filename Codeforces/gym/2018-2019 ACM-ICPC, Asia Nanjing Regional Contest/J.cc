/*************************************************************************
    > File Name: J.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年10月12日 星期六 11时05分46秒
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
constexpr int N = 1E6+10;

int prime[N],a[N],cnt;
bool vis[N];
vector<int> v[N];
void init()
{
	for(int i = 2; i < N; ++i) {
		if(vis[i] == 0) prime[cnt++] = i;
		for(int j = 0; j < cnt; ++j) {
			if(prime[j] * i >= N) break;
			vis[i * prime[j]] = 1;
			if(i % prime[j] == 0) break;
		}
	}
}

int get(int pos)
{
	int x = a[pos];
	map<int,int> foo;
	for(int i = 0; i < cnt && x >= prime[i] * prime[i]; ++i) {
		if(x % prime[i] == 0) {
			foo[prime[i]] = 1;
			v[pos].push_back(prime[i]);
			while(x % prime[i] == 0) {
				x /= prime[i];
			}
		}
	}
	int ret = foo.size();
	if(x > 1) ret++, v[pos].push_back(x);
	return ret;
}

void solve(int n)
{
	for(int i = 1; i <= n; ++i) {
		get(i);
	}
	bool has[N];
	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		set<int> s;
		for(int j = i; j <= n; ++j) {
			for(auto k : v[j]) {
				s.insert(k);
			}
			dbg(i,j,s.size());
			ans += s.size();
		}
	}
	cout << ans << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	init();
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
	}
	solve(n);
    return 0;
}
