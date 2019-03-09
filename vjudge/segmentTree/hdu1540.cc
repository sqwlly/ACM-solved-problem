/*************************************************************************
    > File Name: hdu1540.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月09日 星期六 13时26分51秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 5E4+10;
struct node{
	int lt_len,rt_len,len;
}tr[N << 2];

#define len(x) tr[x].len
#define r_len(x) tr[x].rt_len
#define l_len(x) tr[x].lt_len

void pushup(int rt,int l,int r,int mid)
{
	len(rt) = max(len(rt << 1), len(rt << 1 | 1));
	len(rt) = max(len(rt), l_len(rt << 1 | 1) + r_len(rt << 1));
	l_len(rt) = l_len(rt << 1); r_len(rt) = r_len(rt << 1 | 1); 
	if(l_len(rt) == mid - l + 1) l_len(rt) += l_len(rt << 1 | 1);
	if(r_len(rt) == r - mid) r_len(rt) += r_len(rt << 1);
}

void build(int rt,int l,int r)
{
	if(l == r) {
		tr[rt].rt_len = tr[rt].lt_len = tr[rt].lt_len = 1;
		return;
	}
	int mid = l + r >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	pushup(rt, l, r, mid);
}

void update(int rt,int l,int r,int x,int d)
{
	if(l == x && r == x) {
		len(rt) = l_len(rt) = r_len(rt) = d;
		return;	
	}
	int mid = l + r >> 1;
	if(x <= mid) update(rt << 1, l, mid, x, d);
	else update(rt << 1 | 1, mid + 1, r, x, d);
	pushup(rt, l, r, mid);
}

int query(int rt,int l,int r,int x)
{
	if(len(rt) == 0 || len(rt) == r - l + 1) {
		return len(rt);
	}
	int mid = l + r >> 1;
	if(x <= mid) {
		if(mid - r_len(rt << 1) < x) {
			return r_len(rt << 1) + l_len(rt << 1 | 1);
		}
		return query(rt << 1, l, mid, x);
	}else {
		if(mid + l_len(rt << 1 | 1) >= x) {
			return l_len(rt << 1 | 1) + r_len(rt << 1);
		}
		return query(rt << 1 | 1, mid + 1, r, x);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,m,x;
	while(cin >> n >> m) {
		build(1, 1, n);
		stack<int> st;
		char c;
		for(int i = 0; i < m; ++i) {
			cin >> c;
			if(c == 'D') {
				cin >> x;
				st.push(x);
				update(1, 1, n, x, 0);
			}else if(c == 'Q') {
				cin >> x;
				cout << query(1, 1, n, x) << endl;
			}else{
				if(!st.empty()) {
					update(1, 1, n, st.top(), 1);
					st.pop();
				}
			}
		}
	}
    return 0;
}
