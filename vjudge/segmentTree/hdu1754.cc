/*************************************************************************
    > File Name: hdu1754.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年02月27日 星期三 18时31分36秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 2E5+10;
int tr[N << 2];

void pushup(int rt)
{
	tr[rt] = max(tr[rt << 1], tr[rt << 1 | 1]);
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
		tr[rt] = y;
		return;
	}
	int mid = l + r >> 1;
	if(x <= mid)
		update(rt << 1, l, mid, x, y);
	else
		update(rt << 1 | 1, mid + 1, r, x, y);
	pushup(rt);
}

int query(int rt,int l,int r,int x,int y)
{
	if(x <= l && r <= y) {
		return tr[rt];
	}
	int mid = l + r >> 1, a = 0, b = 0;
	if(x <= mid) a = query(rt << 1, l, mid, x, y);
	if(y > mid) b = query(rt << 1 | 1, mid + 1, r, x, y);
	return max(a,b);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,m,x,y;
	while(cin >> n >> m) {
		build(1,1,n);
		string s;
		while(m--) {
			cin >> s >> x >> y;
			if(s[0] == 'Q') {
				cout << query(1, 1, n, x, y) << endl;
			}else {
				update(1, 1, n, x, y);
			}
		}
	}
    return 0;
}
