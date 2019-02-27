/*************************************************************************
    > File Name: hdu1698.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年02月26日 星期二 10时07分31秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 1E5+10;
int tr[N << 2],add[N << 2];
#define L (rt << 1)
#define R (rt << 1 | 1)
void pushup(int rt)
{
	tr[rt] = tr[L] + tr[R];
}

void pushdown(int rt,int l,int r,int mid)
{
	if(add[rt]) {
		add[L] = add[rt];
		add[R] = add[rt];
		tr[L] = (mid - l + 1) * add[rt];
		tr[R] = (r - mid) * add[rt];
		add[rt] = 0;
	}
}

void build(int rt,int l,int r)
{
	add[rt] = 0;
	if(l == r) {
		tr[rt] = 1;
		return;
	}
	int mid = l + r >> 1;
	build(L, l, mid);
	build(R, mid + 1, r);
	pushup(rt);
}

void update(int rt,int l,int r,int x,int y,int v)
{
	if(l >= x && r <= y) {
		add[rt] = v;
		tr[rt] = (r - l + 1) * v;
		return;
	}
	int mid = l + r >> 1;
	pushdown(rt, l, r, mid);
	if(x <= mid) {
		update(L, l, mid, x, y, v);
	}
	if(y > mid) {
		update(R, mid + 1, r, x, y, v);
	}
	pushup(rt);
}

int query(int rt,int l,int r,int x,int y)
{
	if(l >= x && r <= y) {
		return tr[rt];
	}
	int mid = l + r >> 1, ret = 0;
	pushdown(rt, l, r, mid);
	if(x <= mid) {
		ret += query(L, l, mid, x, y);
	}
	if(y > mid) {
		ret += query(R, mid + 1, r, x, y);
	}
	return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	for(int i = 0; i < T; ++i) {
		int n,q,x,y,z;
		cin >> n >> q;
		build(1,1,n);
		while(q--) {
			cin >> x >> y >> z;
			update(1,1,n,x,y,z);
		}
		cout << "Case "<< (i + 1) << ": The total value of the hook is " << tr[1] << "." << endl;
	}
    return 0;
}
