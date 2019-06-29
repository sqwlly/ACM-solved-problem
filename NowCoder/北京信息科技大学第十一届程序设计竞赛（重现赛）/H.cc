/*************************************************************************
    > File Name: H.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年06月29日 星期六 13时02分29秒
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
const int N = 1E5;
int sum[N << 2],add[N << 2];

void push_up(int rt)
{
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void push_down(int rt,int l,int r)
{
	if(add[rt]) {
		int mid = l + r >> 1;
		add[rt << 1] += add[rt];
		add[rt << 1 | 1] += add[rt];
		sum[rt << 1] += add[rt] * (mid - l + 1);
		sum[rt << 1 | 1] += add[rt] * (r - mid);
		add[rt] = 0;
	}
}

void update(int rt,int l,int r,int x,int y)
{
	if(x <= l && y >= r) {
		sum[rt] += r - l + 1;
		add[rt] += 1;
		return;
	}
	int mid = l + r >> 1;
	push_down(rt,l,r);
	if(x <= mid) {
		update(rt << 1, l, mid, x, y);
	}
	if(y > mid) {
		update(rt << 1 | 1, mid + 1, r, x, y);
	}
	push_up(rt);
}

int query(int rt,int l,int r,int x,int y)
{
	if(x <= l && y >= r) {
		return sum[rt];
	}
	int mid = l + r >> 1, ret = 0;
	push_down(rt,l,r);
	if(x <= mid) {
		ret += query(rt << 1, l, mid, x, y);
	}
	if(y > mid) {
		ret += query(rt << 1 | 1, mid + 1, r, x, y);
	}
	return ret;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,q;
	cin >> n >> q;
	while(q--) {
		int l,r;
		cin >> l >> r;
		update(1, 1, n, l, r);
	}
	for(int i = 1; i <= n; ++i) {
		cout << query(1, 1, n, i, i) << (i == n ? '\n' : ' ');
	}
    return 0;
}
