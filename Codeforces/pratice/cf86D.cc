/*************************************************************************
    > File Name: cf86D.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年05月15日 星期三 19时26分33秒
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
const int N = 2E5+10;
int BLOCK;
struct query{
	int id,l,r;
	bool operator < (const query & u) const {
		if(u.l / BLOCK != l / BLOCK) return u.l / BLOCK < l / BLOCK;
		return u.r < r;
	}
}q[N];
int a[N], cnt[N * 5];
LL ans[N], ret;
inline void add(int x)
{
	ret -= 1LL * cnt[x] * cnt[x] * x;
	cnt[x]++;
	ret += 1LL * cnt[x] * cnt[x] * x;
}

inline void remove(int x)
{
	ret -= 1LL * cnt[x] * cnt[x] * x;
	cnt[x]--;
	ret += 1LL * cnt[x] * cnt[x] * x;
}


void solve(int t)
{
	int curL = 0, curR = 0, L, R;
	ret = 0;
	for(int i = 0; i < t; ++i) {
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
		ans[q[i].id] = ret;
	}
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,t;
	cin >> n >> t;
	BLOCK = sqrt(n);
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for(int i = 0; i < t; ++i) {
		cin >> q[i].l >> q[i].r;
		q[i].l--, q[i].r--;
		q[i].id = i;
	}
	sort(q, q + t);
	solve(t);
	for(int i = 0; i < t; ++i) {
		cout << ans[i] << '\n';
	}
    return 0;
}
