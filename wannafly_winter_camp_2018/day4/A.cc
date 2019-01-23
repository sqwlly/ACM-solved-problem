/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年01月23日 星期三 15时48分38秒
 ************************************************************************/

#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
const int N = 100100;
struct node{
	int id,x,y;
	LL cost;
	node() {}
	node(int a,int b,int c,LL d) {
		id = a; x = b; y = c; cost = d;
	}
};

vector<node> v[N];
bool vis[N];
int n,m;
LL bfs(int sx,int sy)
{
	queue<node> q;
	q.push(node(1,sx,sy,0));
	while(!q.empty()) {
		node cur = q.front();
		q.pop();
		if(cur.id == n && vis[n]) {
			return cur.cost;
		}
		for(int i = 0; i < 2; ++i) {
			node t = v[cur.id][i];
			int dis = abs(cur.x - t.x) + abs(cur.y - t.y);
			t.cost = cur.cost + dis;
			vis[t.id] = 1;
			q.push(t);
		}
	}
	return -1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	cin >> n >> m;
	long long ans = 0;
	int x,y;
	int x1,y1,x2,y2;
	cin >> x1 >> y1 >> x2 >> y2;
	for(int i = 3; i <= n; ++i) {
		scanf("%d %d",&x,&y);
		if(i & 1)
			v[i - 2].push_back(node(i - 1, x,y,0));
		else
			v[i - 3].push_back(node(i - 2, x,y,0));
	}
	v[n].push_back(node(1, x1, y1, 0));
	v[n].push_back(node(1, x2, y2, 0));
	LL t1 = bfs(x1,y1);
	LL t2 = bfs(x2,y2);
	cout << min(t1,t2) << endl;
    return 0;
}
