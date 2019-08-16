/*************************************************************************
    > File Name: hdu4578.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年05月12日 星期日 11时13分50秒
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
const int N = 1E5+10, mod = 10007;
typedef long long LL;

struct node{
	LL l,r,sum1,sum2,sum3;
	LL add,mul,alt;

	void update(LL x,int d)
	{
		if(d == 3) {
			x %= mod;
			sum1 = (r - l + 1) * x % mod;
			sum2 = (r - l + 1) * x % mod * x % mod;
			sum3 = (r - l + 1) * x % mod * x % mod * x % mod;
			alt = x;
			mul = 1;
			add = 0;
		}else if(d == 2) {
			x %= mod;
			sum1 = sum1 % mod * x % mod;
			sum2 = sum2 % mod * x % mod * x % mod;
			sum3 = sum3 % mod * x % mod * x % mod * x % mod;
			mul = mul % mod * x % mod;
			add = add % mod * x % mod;
		}else if(d == 1) {
			x %= mod;
			sum3 = (sum3 % mod + 3 * x % mod * sum2 % mod + 3 * x % mod * x % mod * sum1 % mod + (r - l + 1) % mod * x % mod * x % mod * x % mod) % mod;
			sum2 = (sum2 % mod + 2 * x % mod * sum1 % mod + (r - l + 1) % mod * x % mod * x % mod) % mod;
			sum1 = (sum1 % mod + (r - l + 1) % mod * x % mod) % mod;
			add = (add % mod + x) % mod;
		}
	}	

}tr[N << 2];

#define L (rt << 1)
#define R (rt << 1 | 1)
void pushup(int rt)
{
	tr[rt].sum1 = (tr[L].sum1 + tr[R].sum1) % mod;
	tr[rt].sum2 = (tr[L].sum2 + tr[R].sum2) % mod;
	tr[rt].sum3 = (tr[L].sum3 + tr[R].sum3) % mod;
}

void pushdown(int rt,int l,int r)
{
	int mid = l + r >> 1;
	if(tr[rt].alt) {
		tr[L].update(tr[rt].alt,3);
		tr[R].update(tr[rt].alt,3);
		tr[rt].alt = 0;
	}

	if(tr[rt].mul != 1) {
		tr[L].update(tr[rt].mul,2);
		tr[R].update(tr[rt].mul,2);
		tr[rt].mul = 1;
	}

	if(tr[rt].add) {
		tr[L].update(tr[rt].add,1);
		tr[R].update(tr[rt].add,1);
		tr[rt].add = 0;
	}

}

void build(int rt,int l,int r)
{
	tr[rt].add = tr[rt].alt = 0;
	tr[rt].mul = 1;
	tr[rt].l = l, tr[rt].r = r;
	tr[rt].sum1 = tr[rt].sum2 = tr[rt].sum3 = 0;
	if(l == r) {
		return;
	}
	int mid = l + r >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	pushup(rt);
}

void update(int rt,int l,int r,int x,int y,LL v,int c)
{
	if(l >= x && y >= r) {
		if(c == 3) {
		//	tr[rt].alt = v % mod;
			tr[rt].update(v,3);
		}else if(c == 2) {
			//tr[rt].mul = tr[rt].mul * v % mod;
			tr[rt].update(v,2);
		}else if(c == 1) {
		//	tr[rt].add = (tr[rt].add % mod + v) % mod;
			tr[rt].update(v,1);
		}
		return;
	}
	int mid = l + r >> 1;
	pushdown(rt, l, r);
	if(x <= mid) {
		update(rt << 1, l, mid, x, y, v, c);
	}
	if(y > mid) {
		update(rt << 1 | 1, mid + 1, r, x, y, v, c);
	}
	pushup(rt);
}

LL query(int rt,int l,int r,int x,int y,int p)
{
	if(x <= l && r <= y) {
		if(p == 1) {
			return tr[rt].sum1;
		}else if(p == 2) {
			return tr[rt].sum2;
		}else if(p == 3) {
			return tr[rt].sum3;
		}
	}
	int mid = l + r >> 1;
	pushdown(rt, l, r);
	LL ret = 0;
	if(x <= mid) {
		ret = (ret + query(rt << 1, l, mid, x, y, p)) % mod;
	}
	if(y > mid) {
		ret = (ret + query(rt << 1 | 1, mid + 1, r, x, y, p)) % mod;
	}
	return ret % mod;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	int n,m,x,y,p,c;
	while(cin >> n >> m && (n + m)) {
		build(1, 1, n);
		for(int i = 0; i < m; ++i) {
			cin >> c >> x >> y >> p;
			if(c != 4) {
				update(1, 1, n, x, y, p * 1LL, c);
			}else{
				cout << query(1, 1, n, x, y, p) << '\n';
			}
		}
	}
    return 0;
}
