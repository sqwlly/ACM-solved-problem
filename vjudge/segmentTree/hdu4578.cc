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
const int N = 1E6+10, mod = 10007;
typedef long long LL;

struct node{
	int l,r,sum1,sum2,sum3;
	int add,mul,alt;

	void update(int x,int d)
	{
		if(d == 1) {
			sum1 = (r - l + 1) * x % mod;
			sum2 = (r - l + 1) * x % mod * x % mod;
			sum3 = (r - l + 1) * x % mod * x % mod * x % mod;
			alt = x;
			mul = 1;
			add = 0;
		}else if(d == 2) {
			sum1 = 
		}
	}	

};

int sum1[N << 2], sum2[N << 2], sum3[N << 2], add[N << 2], mul[N << 2], alt[N << 2];
#define L (rt << 1)
#define R (rt << 1 | 1)
void pushup(int rt)
{
	sum1[rt] = sum1[L] + sum1[R];
	sum2[rt] = sum2[L] + sum2[R];
	sum3[rt] = sum3[L] + sum3[R];
}

void pushdown(int rt,int l,int r)
{
	int mid = l + r >> 1;
	if(alt[rt]) {
		alt[L] = alt[R] = alt[rt];
		sum1[L] = 
	}
	if(mul[rt]) {
		mul[L] += mul[rt];
		mul[R] += mul[rt];
		
	}

	if(add[rt]) {
		add[L] += add[rt];
		add[R] += add[rt];
		sum1[L] += add[rt] * (mid - l + 1);
		sum1[R] += add[rt] * (r - mid);
	}

}

void build(int rt,int l,int r)
{
	add[rt] = alt[rt] = 0;
	mul[rt] = 1;
	if(l == r) {
		cin >> a[rt];
		return ;
	}
	int mid = l + r >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	pushup(rt);
}

void update(int rt,int l,int r,int x,int y,int v,int d,int c)
{
	if(l >= x && y >= r) {
		if(c == 1) {
			
		}else if(c == 2) {

		}else if(c == 3) {

		}
		return;
	}
	int mid = l + r >> 1;
	pushdown(rt, l, r);
	if(x <= mid) {
		update(rt << 1, l, mid, x, y, v, d, c);
	}
	if(y > mid) {
		update(rt << 1 | 1, mid + 1, r, x, y, v, d, c);
	}
	pushup(rt);
}

LL query(int rt,int l,int r,int x,int y,int p)
{
	if(x <= l && r <= y) {
		if(p == 1) {
			
		}else if(p == 2) {

		}else if(p == 3) {

		}
		return;
	}
	int mid = l + r >> 1;
	pushdown(rt, l, r);
	LL ret = 0;
	if(x <= mid) {
		ret += query(rt << 1, l, mid, x, y, p);
	}
	if(y > mid) {
		ret += query(rt << 1 | 1, mid + 1, r, x, y, p);
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);

    return 0;
}
