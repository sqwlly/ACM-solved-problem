/*************************************************************************
    > File Name: D-query.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年05月14日 星期二 11时32分25秒
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
const int N = 3E4+10, M = 2e5+10, BLOCK = 555; //~sqrt(N)
struct query{
	int id,l,r;
	bool operator < (const query &u) const {
			if(u.l / BLOCK != l / BLOCK) return u.l / BLOCK < l / BLOCK;
			return u.r < r;
	}
}q[M];
int a[N], cnt[M * 10], ans[M], dx, curL, curR, L, R;

inline void add(int x) {
	cnt[x]++;
	if(cnt[x] == 1) {
		dx++;
	}
}

inline void remove(int x) {
	cnt[x]--;
	if(cnt[x] == 0) {
		dx--;
	}
}

void solve(int m)
{
	curL = 0, curR = 0;
	dx = 0;
	for(int i = 0; i < m; ++i) {
		L = q[i].l, R = q[i].r;
		while(curL < L) {
			remove(a[curL++]);
		}
		while(curL > L) {
			add(a[--curL]); 
		}
		while(curR <= R) {
			add(a[curR++]);
		}
		while(curR > R + 1) {
			remove(a[--curR]);
		}
		ans[q[i].id] = dx;
	}
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,m,l,r;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	cin >> m;
	for(int i = 0; i < m; ++i){
		cin >> q[i].l >> q[i].r;
		q[i].l--, q[i].r--;
		q[i].id = i;
	}
	sort(q, q + m);
	solve(m);
	for(int i = 0; i < m; ++i) {
		cout << ans[i] << '\n';
	}
    return 0;
}
