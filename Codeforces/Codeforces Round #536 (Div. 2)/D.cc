/*************************************************************************
    > File Name: D.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年01月31日 星期四 21时43分53秒
 ************************************************************************/

#include<bits/stdc++.h>
#define P pair<int,int>
using namespace std;
const int N = 1E5+10;
//vector<int> e[N];
priority_queue<int,vector<int>,greater<int> > e[N];
bool vis[N];
vector<int> ans;
priority_queue<int,vector<int>,greater<int> > pq;
void bfs()
{
	pq.push(1);
	vis[1] = 1;
	ans.push_back(1);
	while(!pq.empty()) {
		int cur = pq.top();
		pq.pop();
		for(int i = 0; !e[cur].empty(); e[cur].pop()) {
			int v = e[cur].top();
			if(vis[v] == 0) {
				vis[v] = 1;
				ans.push_back(v);
			}
			pq.push(v);
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n,m,x,y;
	cin >> n >> m;
	for(int i = 0; i < m; ++i) {
		scanf("%d%d",&x,&y);
		e[x].push(y);
		e[y].push(x);
	}
	bfs();
	int len = ans.size();
	for(int i = 0; i < len; ++i) {
		printf("%d%c",ans[i],i==len-1?'\n':' ');
	}
    return 0;
}
