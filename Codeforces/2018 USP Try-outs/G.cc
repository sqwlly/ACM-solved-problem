/*************************************************************************
    > File Name: G.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年09月03日 星期二 23时33分31秒
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
int L[N << 2], R[N << 2];

void pushup(int rt)
{
	L[rt] = max(L[rt << 1], L[rt << 1 | 1]);
	R[rt] = min(R[rt << 1], R[rt << 1 | 1]);
}

void build(int rt,int l,int r)
{
	L[rt] = INT_MIN, R[rt] = INT_MAX;
	if(l == r) {
		cin >> L[rt] >> R[rt];
		return;
	}
	int mid = l + r >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	pushup(rt);
}

void update(int rt,int l,int r,int x,int y,int z)
{
	if(l == r && l == z) {
		L[rt] = x;
		R[rt] = y;
		return;
	}
	int mid = l + r >> 1;
	if(z <= mid) {
		update(rt << 1, l, mid, x, y, z);
	}else{
		update(rt << 1 | 1, mid + 1, r, x, y, z);
	}
	pushup(rt);
}	

int query(int rt,int l,int r,int x,int y,int d)
{
	if(x <= l && r <= y) {
		return (d ? L[rt] : R[rt]); 
	}
	int mid = l + r >> 1, L = INT_MIN, R = INT_MAX;
	if(x <= mid) {
		if(d) {
			L = max(L, query(rt << 1, l, mid, x, y, d));
		}else{
			R = min(R, query(rt << 1, l, mid, x, y, d));
		}
	}
	if(y > mid){
		if(d) {
			L = max(L, query(rt << 1 | 1, mid + 1, r, x, y, d));
		}else{
			R = min(R, query(rt << 1 | 1, mid + 1, r, x, y, d));
		}
	}
	return (d ? L : R);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,q,l,r,i;
	cin >> n >> q;
	build(1, 1, n);
	char c;
	while(q--) {
		cin >> c;
		if(c == '?') {
			cin >> l >> r;
			cout << max(query(1, 1, n, l, r, 0) - query(1, 1, n, l, r, 1) + 1,0) << '\n';
		}else{
			cin >> i >> l >> r;
			update(1, 1, n, l, r, i);
		}
	}
    return 0;
}
