/*************************************************************************
    > File Name: poj3468.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年02月27日 星期三 16时43分10秒
 ************************************************************************/

#include<iostream>
#include<string>
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
typedef long long LL;
using namespace std;
const int N = 1E5+10;
LL tr[N << 2], add[N << 2];

void pushup(int rt)
{
	tr[rt] = tr[rt << 1] + tr[rt << 1 | 1];
}

void pushdown(int rt,int l,int r,int mid)
{
	if(add[rt]) {
		add[rt << 1] += add[rt];
		add[rt << 1 | 1] += add[rt];
		tr[rt << 1] += add[rt] * (mid - l + 1);
		tr[rt << 1 | 1] += add[rt] * (r - mid);
		add[rt] = 0;
	}
}

void build(int rt,int l,int r)
{
	if(l == r){
		cin >> tr[rt];
		return;
	}
	int mid = l + r >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	pushup(rt);
}

void update(int rt,int l,int r,int x,int y,int z)
{
	if(x <= l && r <= y) {
		tr[rt] += 1LL * z * (r - l + 1);
		add[rt] +=  z;
		return;
	}
	int mid = l + r >> 1;
	pushdown(rt, l, r, mid);
	if(x <= mid) update(rt << 1, l, mid, x, y, z);
	if(y > mid) update(rt << 1 | 1, mid + 1, r, x, y, z);
	pushup(rt);
}

LL query(int rt,int l,int r,int x,int y) 
{
	if(x <= l && r <= y) {
		return tr[rt];		
	}
	int mid = l + r >> 1;
	pushdown(rt, l, r, mid);
	LL ret = 0;
	if(x <= mid)
		ret += query(rt << 1, l, mid, x, y);
	if(y > mid)
		ret += query(rt << 1 | 1, mid + 1, r, x, y);
	return ret;

}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,q,x,y,z;
	cin >> n >> q;
	build(1,1,n);
	string s;
	while(q--) {
		cin >> s >> x >> y;
		if(s[0] == 'Q') {
			cout << query(1, 1, n, x, y) << endl;
		}else if(s[0] == 'C'){
			cin >> z;
			update(1, 1, n, x, y, z);
		}
	}
    return 0;
}
