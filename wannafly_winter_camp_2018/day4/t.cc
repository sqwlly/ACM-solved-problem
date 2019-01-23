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
    bool operator < (const node &u) const {
        return cost > u.cost;
    }
};

vector<node> v[N];
int vis[N];
int n,m;
LL bfs(int sx,int sy)
{
    priority_queue<node> q;
    q.push(node(1,sx,sy,0));
    vis[1] = 1;
    while(!q.empty()) {
        node cur = q.top();
        q.pop();
        if(cur.id == 1 && vis[1] == 2) {
            return cur.cost;
        }
        for(int i = 0; i < v[cur.id].size(); ++i) {
            node t = v[cur.id][i];
          //  if(vis[cur.id] > 2) continue;
            int dis = abs(cur.x - t.x) + abs(cur.y - t.y);
            t.cost = cur.cost + dis;
            vis[t.id]++;
            q.push(t);
        }
    }
    return -1;
}
int x[N * 2],y[N * 2];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    cin >> n >> m;
    long long ans = 0;
  //  int x1,y1,x2,y2;
    for(int i = 1; i <= 2*n; ++i) {
        scanf("%d %d", &x[i], &y[i]);
    }
    for(int i = 1; i < n; ++i) {
        v[i].push_back(node(i + 1, x[i * 2 + 1], y[i * 2 + 1], 0));
        v[i].push_back(node(i + 1, x[i * 2 + 2], y[i * 2 + 2], 0));
        v[i + 1].push_back(node(i, x[2 * i - 1], y[2 * i - 1], 0));
        v[i + 1].push_back(node(i, x[2 * i], y[2 * i], 0));
    }
    v[n].push_back(node(n, x[n - 1], y[n - 1], 0));
    v[n].push_back(node(n, x[n], y[n], 0));
    LL t1 = bfs(x[1],y[1]);
    LL t2 = bfs(x[2],y[2]);
    cout << min(t1,t2) << endl;
    return 0;
}

