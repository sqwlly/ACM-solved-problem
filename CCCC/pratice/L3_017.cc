/*************************************************************************
    > File Name: L3_017.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月07日 星期四 13时03分17秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 1E5+10;
int tr[N << 2], add[N << 2], a[N];
struct node{
	int l, r;
	bool operator < (const node &u) const {
		return r < u.r;
	}
}seg[N];

void pushup(int rt)
{
	tr[rt] = min(tr[rt << 1], tr[rt << 1 | 1]);
}

void pushdown(int rt,int l,int r,int mid)
{
	if(add[rt]) {
		add[rt << 1] += add[rt];
		add[rt << 1 | 1] += add[rt];
		tr[rt << 1] += add[rt];
		tr[rt << 1 | 1] += add[rt];
		add[rt] = 0;
	}
}

void build(int rt,int l,int r)
{
	if(l == r) {
		tr[rt] = a[l];
		return;
	}
	int mid = l + r >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	pushup(rt);
}

void update(int rt,int l,int r,int x,int y,int v)
{
	if(x <= l && r <= y) {
		add[rt] += v;
		tr[rt] += v;
		return;
	}
	int mid = l + r >> 1;
	pushdown(rt, l, r, mid);
	if(x <= mid) update(rt << 1, l, mid, x, y, v);
	if(y > mid) update(rt << 1 | 1, mid + 1, r, x, y, v);
	pushup(rt);
}

void query(int rt,int l,int r,int x,int y,long long &MIN)
{
	if(x <= l && r <= y) {
		MIN = min(MIN, 1LL * tr[rt]);
		return;
	}
	int mid = l + r >> 1;
	pushdown(rt, l, r, mid);
	if(x <= mid) query(rt << 1, l, mid, x, y, MIN);
	if(y > mid) query(rt << 1 | 1, mid + 1, r, x, y, MIN);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,q,l,r;
	cin >> n >> q;
	for(int i = 1; i <= n - 1; ++i) {
		cin >> a[i];
	}
	build(1, 1, n - 1);
	for(int i = 0; i < q; ++i) {
		cin >> l >> r;
		if(l > r) swap(l, r);
		seg[i].l = l + 1, seg[i].r = r;
	}
	sort(seg, seg + q);
	long long ans = 0, MIN = LLONG_MAX >> 1;
	for(int i = 0; i < q; ++i) {
		MIN = LLONG_MAX >> 1;
	//	DEBUG(seg[i].l); DEBUG(seg[i].r);
		query(1, 1, n - 1, seg[i].l, seg[i].r, MIN);
		ans += MIN;
	//	DEBUG(MIN);
		update(1, 1, n - 1, seg[i].l, seg[i].r, -MIN);
	}
	cout << ans << endl;

	return 0;
}
