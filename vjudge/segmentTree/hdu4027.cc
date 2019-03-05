/*************************************************************************
    > File Name: hdu4027.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月05日 星期二 21时31分23秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

typedef long long LL;
using namespace std;
const int N = 1E5 + 10;
LL tr[N << 2];
void pushup(int rt)
{
	tr[rt] = tr[rt << 1] + tr[rt << 1 | 1];
}

void build(int rt,int l,int r)
{
	if(l == r) {
		cin >> tr[rt];
		return;
	}
	int mid = l + r >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	pushup(rt);
}

void update(int rt,int l,int r,int x,int y)
{
	if(l == r) {
		tr[rt] = sqrt(tr[rt]);
		return;
	}
	if(tr[rt] == (r - l + 1)) return;
	int mid = l + r >> 1;
	if(x <= mid) {
		update(rt << 1, l, mid, x, y);
	}
	if(y > mid) {
		update(rt << 1 | 1, mid + 1, r, x, y);
	}
	pushup(rt);
}

LL query(int rt,int l,int r,int x,int y)
{
	if(x <= l && r <= y) {
		return tr[rt];
	}
	int mid = l + r >> 1;
	LL ret = 0;
	if(x <= mid) {
		ret += query(rt << 1, l, mid, x, y);
	}
	if(y > mid) {
		ret += query(rt << 1 | 1, mid + 1, r, x, y);
	}
	return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,q,c,x,y, w = 1;
	while(cin >> n) {
		build(1, 1, n);
		cin >> q;
		cout << "Case #" << (w++) << ":\n";
		while(q--) {
			cin >> c >> x >> y;
			if(x > y) swap(x, y);
			if(c) {
				cout << query(1, 1, n, x, y) << endl;
			}else{
				update(1, 1, n, x, y);
			}
		}
		cout << endl;
	}
    return 0;
}
