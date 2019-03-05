/*************************************************************************
    > File Name: poj3264.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月05日 星期二 19时21分50秒
 ************************************************************************/

#include<iostream>
#define max(a,b)  (a > b ? a : b)
#define min(a,b)  (a > b ? b : a)
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 50002;
int Max[N << 2], Min[N << 2],MAX,MIN;

void pushup(int rt)
{
	Max[rt] = max(Max[rt << 1], Max[rt << 1 | 1]);
	Min[rt] = min(Min[rt << 1], Min[rt << 1 | 1]);
}

void build(int rt,int l,int r)
{
	if(l == r) {
		int x;
		cin >> x;
		Max[rt] = x;
		Min[rt] = x;
		return;
	}
	int mid = l + r >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	pushup(rt);
}

void query(int rt,int l,int r,int x,int y)
{
	if(x <= l && r <= y) {
		MAX = max(MAX, Max[rt]);
		MIN = min(MIN, Min[rt]);
		return;
	}
	int mid = l + r >> 1;
	if(x <= mid) 
		query(rt << 1, l, mid, x, y);
	if(y > mid)
		query(rt << 1 | 1, mid + 1, r, x, y);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,q,x,y;
	cin >> n >> q;
	build(1, 1, n);
	while(q--) {
		MIN = 1e9, MAX = -1;
		cin >> x >> y;
		query(1, 1, n, x, y);
		cout << MAX - MIN << endl;
	}
    return 0;
}
