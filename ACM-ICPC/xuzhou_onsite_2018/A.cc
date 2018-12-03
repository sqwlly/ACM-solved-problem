/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年09月16日 星期日 12时08分52秒
 ************************************************************************/

#include<bits/stdc++.h>
typedef unsigned long long LL;
const int N = 2E5+100, M = 2E5+100, mod = 1e9 + 7;
int F[N], tot;
using namespace std;
struct Edge{
	LL u,v,w;
}e[N];
void add(LL u,LL v,LL w) 
{
	e[tot].u = u;
	e[tot].v = v;
	e[tot++].w = w;
}

bool cmp(Edge a,Edge b)
{
	return a.w < b.w;
}

LL find1(LL x)
{
	if(F[x] == -1) return x;
	return F[x] = find1(F[x]);
}

unsigned long long k1,k2;
unsigned long long xorShift128Plus()
{
	unsigned long long k3 = k1, k4 = k2;
	k1 = k4;
	k3 ^= k3 << 23;
	k2 = k3 ^ k4 ^ (k3 >> 17) ^ (k4 >> 26);
	return k2 + k4;
}

int n,m;
void gen()
{
	scanf("%d%d%llu%llu",&n,&m,&k1,&k2);
	for(int i = 1; i <= m; ++i) {
	    LL u = xorShift128Plus() % n + 1;
		LL v = xorShift128Plus() % n + 1;
		LL w = xorShift128Plus();
		add(u,v,w);
		add(v,u,w);
	}
}


LL solve()
{
	memset(F, -1, sizeof F);
	sort(e,e+tot,cmp);
	LL cnt = 0, ans = 0;
	for(int i = 0; i < tot; ++i) {
		LL u = e[i].u;
		LL v = e[i].v;
		LL w = e[i].w;
		LL t1 = find1(u);
		LL t2 = find1(v);
		if(t1 != t2) {
			ans = (ans + w) % mod ;
			F[t1] = t2;
			cnt++;
		}
		if(cnt == n - 1) break;
	}
	if(cnt < n - 1) return 0;
	return ans % mod;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int T;
	scanf("%d",&T);
	while(T--) {
		tot = 0;
		gen();
		LL ans = solve();
		printf("%lld\n", ans);
	}
    return 0;
}
