/*************************************************************************
    > File Name: zoj1610.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年02月27日 星期三 11时15分01秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
//0 1 2 3 4
//|4|4|4|4|
//|1|1|1|4|
//|1|1|1|2|
//|2|2|1|2|
//|3|3|1|2|
const int N = 8010;
int tr[N << 2], ans[N],color[N];

void pushdown(int rt)
{
	if(tr[rt] != -1) {
		tr[rt << 1] = tr[rt];
		tr[rt << 1 | 1] = tr[rt];
		tr[rt] = -1;
	}	
}

void update(int rt,int l,int r,int x,int y,int z)
{
	if(x <= l && r <= y) {
		tr[rt] = z;
		return;
	}
	int mid = l + r >> 1;
	pushdown(rt);
	if(x <= mid) update(rt << 1, l, mid, x, y, z);
	if(y > mid) update(rt << 1 | 1, mid + 1, r, x, y, z);
}

void query(int rt,int l,int r,int x,int y)
{
	if(x <= l && r <= y) {
		if(tr[rt] != -1) {
			for(int i = l; i <= r; ++i) {
				color[i] = tr[rt];
			}
			return;
		}
	}
	if(l == r) return;
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
	int n,x,y,z;
	while(cin >> n) {
		memset(tr, -1, sizeof tr);
		memset(ans, 0, sizeof ans);
		memset(color,-1,sizeof color);
		while(n--) {
			cin >> x >> y >> z;
			if(x >= y) continue;
			update(1,1,N,x + 1,y,z);
		}
		query(1,1,N,1,N);
		for(int i = 1; i < N; ++i) {
			if(color[i] == -1) continue;
			int c = color[i];
			ans[c]++;
			for(; i < N && color[i] == c; ++i);
			i--;
		}
		for(int i = 0; i < N; ++i) {
			if(ans[i]) cout << i << ' ' << ans[i] << endl;
		}
		cout << endl;
	}
    return 0;
}
