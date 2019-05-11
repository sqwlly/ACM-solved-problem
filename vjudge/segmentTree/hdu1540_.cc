#include<bits/stdc++.h>
#define len(x) tr[x]
#define len_l(x) l_len[x]
#define len_r(x) r_len[x]
using namespace std;
const int N = 50010;
int tr[N << 2], l_len[N << 2], r_len[N << 2],n,m;

void pushup(int rt,int l,int r)
{
	int mid = l + r >> 1;
	tr[rt] = max(tr[rt << 1], tr[rt << 1 | 1]);
	//如果左子树的左连续等于左子树区间长度，看是否能更新父亲为左子树区间长度+右子树的最大左连续	
	tr[rt] = max(tr[rt], r_len[rt << 1] + l_len[rt << 1 | 1]);
	l_len[rt] = l_len[rt << 1]; r_len[rt] = r_len[rt << 1 | 1];
	if(l_len[rt] == mid - l + 1) { 
		l_len[rt] += l_len[rt << 1 | 1];
	}
    //如果右子树的右连续等于右子树区间长度，看是否能更新父亲为右子树区间长度+左子树的最大右连续
	if(r_len[rt] == r - mid) { 
		r_len[rt] += r_len[rt << 1];
	}
}

void build(int rt,int l,int r)
{
	if(l == r) {
		tr[rt] = l_len[rt] = r_len[rt] = 1;
		return;
	}
	int mid = l + r >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	pushup(rt, l, r);
}

void update(int rt,int l,int r,int x,int d)
{
	if(l == r && r == x) {
		tr[rt] = l_len[rt] = r_len[rt] = d;
		return;
	}
	int mid = l + r >> 1;
	if(x <= mid) {
		update(rt << 1, l, mid, x, d);
	}else{
		update(rt << 1 | 1, mid + 1, r, x, d);
	}
	pushup(rt, l, r);
}

int query(int rt,int l,int r,int x)
{
	if(tr[rt] == 0 || tr[rt] == r - l + 1) {
		return tr[rt];
	}
	int mid = l + r >> 1;
	if(x <= mid) {
		if(x + r_len[rt << 1] > mid) return r_len[rt << 1] + l_len[rt << 1 | 1];
		return query(rt << 1, l, mid, x);
	}else{
		if(x - l_len[rt << 1 | 1] <= mid) return r_len[rt << 1] + l_len[rt << 1 | 1];
		return query(rt << 1 | 1, mid + 1, r, x);
	}
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	ios::sync_with_stdio(0); cin.tie(0);
	char c; int x;
	while(cin >> n >> m) {
		build(1, 1, n);
		stack<int> st;
		while(m--) {
			cin >> c;
			if(c == 'D') {
				cin >> x;
				update(1, 1, n, x, 0);
				st.push(x);
			}else if(c == 'R') {
				if(st.size() == 0) continue;
				x = st.top(); st.pop();
				update(1, 1, n, x, 1);
			}else if(c == 'Q') {
				cin >> x;
				cout << query(1, 1, n, x) << endl;
			}
		}
	}
	return 0;
}
