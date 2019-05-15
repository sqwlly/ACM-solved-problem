/*************************************************************************
    > File Name: C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年05月15日 星期三 22时51分22秒
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
const int N = 5E5+10;
int f[N],cnt[N];

int getf(int v)
{
	if(f[v] == v) return v;
	return f[v] = getf(f[v]);
}
int num[N];
void mrg(int u,int v)
{
	int p = getf(u);
	int q = getf(v);
	if(p != q) { f[p] = q;
	//	num[u] += num[v];
	}
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,m,x,k,t;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) f[i] = i;
	for(int i = 1; i <= m; ++i) {
		cin >> k;
		if(k) cin >> t;
		for(int j = 1; j < k; ++j) {
			cin >> x;
			mrg(t,x);
		}
	}
	for(int i = 1; i <= n; ++i) {
		cnt[getf(i)]++;
	}
	for(int i = 1; i <= n; ++i) {
		cout << cnt[getf(i)] << ' ';
	}
    return 0;
}
