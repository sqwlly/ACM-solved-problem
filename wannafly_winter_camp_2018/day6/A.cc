/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com
    > Created Time: 2019年01月26日 星期六 16时14分42秒
 ************************************************************************/

#include<bits/stdc++.h>
#define P pair<int,int>
using namespace std;
const int N = 1E5+10;
int dis[N], a[N];

vector<int> e[N];
priority_queue<P, vector<P>, greater<P> > pq;
void dijkstra(int s)
{
    memset(dis,0x3f,sizeof dis);
    pq.push(P(dis[s] = 0, s));
    while(!pq.empty()) {
        P cur = pq.top();
        pq.pop();
        int cost = cur.first;
        int u = cur.second;
        if(dis[u] < cost) continue;
        int len = e[u].size();
        for(int i = 0; i < len; ++i) {
            int v = e[u][i];
            if(dis[u] + 1 < dis[v]) {
                dis[v] = dis[u] + 1;
                pq.push(P(dis[v],v));
            }
        }
    }
}
vector<int> v;
bool cmp(int a,int b)
{
    return dis[a] < dis[b];
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
#endif
    int n, x, y;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i]);
        if (a[i]) v.push_back(i);
    }
    for (int i = 1; i < n; ++i) {
        scanf("%d %d", &x, &y);
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dijkstra(1);
    sort(v.begin(), v.end(), cmp); //按照dis[i]由小到大排序
    int maxcost = 0, pre = 0;
    for (int i = 0; i < v.size(); ++i) {
        maxcost = max(maxcost, dis[v[i]]);
        if (pre >= dis[v[i]]) //因为每次只能逃生一个人，所以如果有相等的dis，则需要等待时间+1，而后面遇到如果dis小于当前时间的也需要+1
            maxcost++;
        pre = maxcost;
    }
    cout << maxcost << endl;
    return 0;
}

