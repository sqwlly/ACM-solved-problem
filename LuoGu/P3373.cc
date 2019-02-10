/*************************************************************************
  > File Name: P3373.cc
  > Author: sqwlly
  > Mail: sqw.lucky@gmail.com 
  > Created Time: 2019年02月10日 星期日 15时40分47秒
 ************************************************************************/

#include<bits/stdc++.h>

typedef long long LL;
using namespace std;
const int N = 1E5+10;
struct node{
	LL add,mul,v;
} tr[N << 2];
int a[N],mod;

void pushup(int rt)
{
	tr[rt].v = (tr[rt << 1].v + tr[rt << 1 | 1].v) % mod;
}
//(x + 2) * 3 = 3 * x + 3 * 2
void pushdown(int rt,int L,int R,int mid)
{
	tr[rt << 1].add = (tr[rt << 1].add * tr[rt].mul + tr[rt].add) % mod;
	tr[rt << 1].mul = (tr[rt << 1].mul * tr[rt].mul) % mod;
	tr[rt << 1 | 1].add = (tr[rt << 1 | 1].add * tr[rt].mul + tr[rt].add) % mod;
	tr[rt << 1 | 1].mul = (tr[rt << 1 | 1].mul * tr[rt].mul) % mod;
	tr[rt << 1].v = (tr[rt << 1].v * tr[rt].mul + tr[rt].add * (mid - L + 1))% mod; //
	tr[rt << 1 | 1].v = (tr[rt << 1 | 1].v * tr[rt].mul + tr[rt].add * (R - mid)) % mod;
	tr[rt].add = 0;
	tr[rt].mul = 1;
}

void build(int rt,int x,int y)
{
	tr[rt].add = 0;
	tr[rt].mul = 1;
	if(x == y) {
		tr[rt].v = a[x];
		return;
	}
	int mid = (x + y) >> 1;
	build(rt << 1, x, mid);
	build(rt << 1 | 1, mid + 1, y);
	pushup(rt);
}

LL query(int rt,int l,int r,int x,int y)
{
	if(y < l || r < x) return 0;
	if(l >= x && r <= y) return rt[tr].v;
	int mid = (l + r) >> 1;
	pushdown(rt,l,r,mid);
	LL ret = 0;
	if(x <= mid) {
		ret = (ret + query(rt << 1, l, mid, x, y)) % mod;
	}
	if(y > mid) {
		ret = (ret + query(rt << 1 | 1, mid + 1, r, x, y)) % mod;
	}
	return ret % mod;
}

void update(int rt,int l,int r,int x,int y,int v,int d)
{
	if(y < l || r < x) return;
	if(l >= x && r <= y) {
		if(d) {
			tr[rt].add = (tr[rt].add + v) % mod;
			tr[rt].v = (tr[rt].v + v * (r - l + 1)) % mod;
		}else{
			tr[rt].v = (v * tr[rt].v) % mod;
			tr[rt].add = (tr[rt].add * v) % mod;
			tr[rt].mul = (tr[rt].mul * v) % mod;
		}
		return;
	}
	int mid = (l + r) >> 1;
	pushdown(rt, l, r, mid);
	if(x <= mid) {
		update(rt << 1, l, mid, x, y, v, d);
	}
	if(y > mid) {
		update(rt << 1 | 1, mid + 1, r, x, y, v, d);
	}
	pushup(rt);
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
#endif
	int n,m,p,x,y,k;
	cin >> n >> m >> mod;
	for(int i = 1; i <= n; ++i) {
		scanf("%d",&a[i]);
	}
	build(1,1,n);
	while(m--) {
		scanf("%d%d%d",&p,&x,&y);
		p--;
		if(p < 2) {
			scanf("%d",&k);
			update(1,1,n,x,y,k,p);
		}else{
			printf("%lld\n",query(1,1,n,x,y));
		}
	}
	return 0;
}
