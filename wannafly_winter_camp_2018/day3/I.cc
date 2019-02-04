/*************************************************************************
    > File Name: I.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年02月03日 星期日 18时49分25秒
 ************************************************************************/

#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
const int N = 2E5+10, mod = 998244353;
LL w[N],v[N],rk[N],f[N];
struct node{
	int fa;
	LL _w,_v;
};
LL _pow(LL a,LL n)
{
	LL ret = 1;
	while(n) {
		if(n & 1) ret = a * ret % mod;
		a = a * a % mod;
		n >>= 1;
	}
	return ret;
}

LL Inv(LL n){ return _pow(n, mod - 2); }

node _find(int x)
{
	if(x == f[x]) return node{x,w[x],v[x]};
	node t = _find(f[x]);
	return node{t.fa, t._w + w[x], t._v + v[x]};
}

void _merge(int x,int y)
{
	int t1 = _find(x).fa;
	int t2 = _find(y).fa;
	if(t1 != t2) {
		w[t1]++;
		v[t1]++;
		w[t2]++;
		if(rk[t1] >= rk[t2]) {
			w[t2] -= w[t1];
			v[t2] -= v[t1];
			f[t2] = t1;
			rk[t1]++;
		}else{
			w[t1] -= w[t2];
			v[t1] -= v[t2];
			f[t1] = t2;
			rk[t2]++;
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	for(int i = 0; i < N; ++i) {
		f[i] = i;
	}
	int n,m,c,x,y;
	cin >> n >> m;
	LL t = _pow(3,n);
	for(int i = 0; i < m; ++i) {
		scanf("%d",&c);
		if(c == 1) {
			scanf("%d %d",&x,&y);
			_merge(x,y);
		}else{
			scanf("%d",&x);
			node t1 = _find(x);
			LL a = t1._v, b = t1._w - t1._v;
			LL ans = t * Inv(_pow(3,b)) % mod * _pow(2,a) % mod * Inv(_pow(3,a)) % mod;
			printf("%lld\n",ans);
		}
	}
    return 0;
}
