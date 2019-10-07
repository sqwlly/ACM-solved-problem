/*************************************************************************
    > File Name: F1.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年09月28日 星期六 11时25分28秒
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

const int N = 2E5+10;
struct edge{
	int nxt,to;
}e[N << 1];

int sum[N << 1], lazy[N << 1];
/**
 * f[u] u的父亲节点, size[u] 以u为根的子树节点个数
 * d[u] u的深度, son[u] u的重儿子
 * rk[u] 当前dfs标号在树中所对应的节点 top[u] 当前节点所在链的顶端节点
 * id[u] 树中每个节点剖分后的新编号(dfs的执行顺序)
 * */
int n,m,r,cnt,mod,tot,v[N],head[N],f[N],d[N],size[N],son[N],rk[N],top[N],id[N];

inline void add(int x,int y)
{
	e[++cnt].nxt = head[x];
	e[cnt].to = y;
	head[x] = cnt;
}

void dfs1(int u)
{
	size[u] = 1;
	for(int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		if(!d[v]) {
			d[v] = d[u] + 1;
			f[v] = u;
			dfs1(v);
			size[u] += size[v];
			if(size[v] > size[son[u]]) son[u] = v; //size最大的作为重儿子
		}
	}
}

void dfs2(int u,int t) 
{
	id[u] = ++tot;
	rk[tot] = v[u];
	top[u] = t;
	if(!son[u]) return;
	dfs2(son[u], t);
	//优先进入重儿子来保证一条重链上各个节点dfs序连续
	//一个点和他的重儿子处于同一条重链，所以重儿子所在重链顶端还是t
	for(int i = head[u]; i; i = e[i].nxt) {
		int v = e[i].to;
		if(v != son[u] && v != f[u]) dfs2(v,v);
	}
}

inline void pushup(int rt)
{
	sum[rt] = (sum[rt << 1] + sum[rt << 1 | 1]) % mod;
}

inline void pushdown(int rt,int l,int r)
{
	if(lazy[rt]) {
		int mid = l + r >> 1;
		(lazy[rt << 1] += lazy[rt]) %= mod;
		(lazy[rt << 1 | 1] += lazy[rt]) %= mod;
		(sum[rt << 1] += lazy[rt] * (mid - l + 1)) %= mod;
		(sum[rt << 1 | 1] += lazy[rt] * (r - mid)) %= mod;
		lazy[rt] = 0;
	}
}


void build(int rt,int l,int r)
{
	if(l == r) {
		sum[rt] = rk[l];
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
		(lazy[rt] += v) %= mod;
		(sum[rt] += v * 1LL * (r - l + 1)) %= mod;
		return;
	}
	pushdown(rt,l,r);
	int mid = l + r >> 1;
	if(x <= mid) {
		update(rt << 1, l, mid, x, y, v);
	}
	if(y > mid) {
		update(rt << 1 | 1, mid + 1, r, x, y, v);
	}
	pushup(rt);
}

int query(int rt,int l,int r,int x,int y)
{
	if(x <= l && r <= y) {
		return sum[rt] % mod;
	}
	if(l > y || r < x) return 0;
	int mid = l + r >> 1, ret = 0;
	pushdown(rt,l,r);
	if(x <= mid) 
		(ret += query(rt << 1, l, mid, x, y)) %= mod;
	if(y > mid) 
		(ret += query(rt << 1 | 1, mid + 1, r, x, y)) %= mod;
	return ret % mod;
}

inline int query_pth(int x,int y)
{
	int ans = 0, fx = top[x], fy = top[y];
	while(fx != fy) {
		if(d[fx] >= d[fy]) {
			(ans += query(1, 1, tot, id[fx], id[x])) %= mod;  //线段树区间求和，处理这条重链的贡献
			x = f[fx], fx = top[x]; //将x设置成原链头的父亲结点，走轻边，继续循环
		}else{
			(ans += query(1, 1, tot, id[fy], id[y])) %= mod;
			y = f[fy], fy = top[y];
		}
	}
	//循环结束，两点位于同一重链上，但两点不一定为同一点，所以我们还要统计这两点之间的贡献
	if(id[x] <= id[y]) (ans += query(1, 1, tot, id[x], id[y])) %= mod;
	else (ans += query(1, 1, tot, id[y], id[x])) %= mod;
	return ans;
}

inline void update_pth(int x,int y,int c)
{
	int fx = top[x], fy = top[y];
	while(fx != fy) {
		if(d[fx] < d[fy]) swap(x,y),swap(fx,fy);
		update(1, 1, tot, id[fx], id[x], c);
		x = f[fx], fx = top[x];
	}
	if(id[x] > id[y]) swap(x,y);
	update(1, 1, tot, id[x], id[y], c);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m >> r >> mod;
	for(int i = 1; i <= n; ++i) {
		cin >> v[i]; 
		v[i] %= mod;
	}
	int x,y,z,c;
	for(int i = 1; i < n; ++i) {
		cin >> x >> y;
		add(x,y); add(y,x);
	}
	d[r] = 1; f[r] = 1;
	dfs1(r); dfs2(r,r);
	build(1, 1, n);
	for(int i = 0; i < m; ++i) {
		cin >> c;
		if(c == 1) {
			cin >> x >> y >> z;	
			update_pth(x, y, z);
		}else if(c == 2) {
			cin >> x >> y;
			cout << query_pth(x, y) << '\n';
		}else if(c == 3) {
			cin >> x >> z;
			update(1, 1, n, id[x], id[x] + size[x] - 1, z);
		}else{
			cin >> x;
			cout << query(1, 1, n, id[x], id[x] + size[x] - 1) << '\n';
		}
	}
    return 0;
}
