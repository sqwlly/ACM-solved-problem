/*************************************************************************
    > File Name: C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年02月25日 星期一 00时23分32秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
string s[55];
struct node{
	int x,y,prex,prey,cost;
	bool operator < (const node & u) const {
		return cost > u.cost;
	}
};

int dir[4][2] = {1,0,0,1,-1,0,0,-1},n;
int bfs(int r1,int c1,int r2,int c2)
{
	priority_queue<node> pq;
	node cur,nxt;
	pq.push(node{r1,c1,r1,c1,0});
	while(!pq.empty()) {
		cur = pq.top(); pq.pop();
		if(cur.x == r2 && cur.y == c2) {
			return cur.cost;
		}
		for(int i = 0; i < 4; ++i) {
			int tx = cur.x + dir[i][0];
			int ty = cur.y + dir[i][1];
			if(tx >= n || tx <= 0 || ty >= n || ty <= 0) continue;
			nxt.x = tx, nxt.y = ty;
			if(s[tx - 1][ty - 1] == '1') {
				nxt.prex = cur.x;
				nxt.prey = cur.y;
			}else{
				nxt.prex = tx;
				nxt.prey = ty;
			}
			nxt.cost = cur.cost + (nxt.x - nxt.prex) * (nxt.x - nxt.prex) + (nxt.y - nxt.prey) * (nxt.y - nxt.prey);
			pq.push(nxt);
		}
	}
	return -1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
   // ios::sync_with_stdio(false); cin.tie(0);
	int r1,r2,c1,c2;
	cin >> n >> r1 >> c1 >> r2 >> c2;
	for(int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	cout << 1 << endl;
	printf("%d %d %d %d",r1,c1,r2,c2);
	cout << bfs(r1,c1,r2,c2) << endl;;
    return 0;
}
