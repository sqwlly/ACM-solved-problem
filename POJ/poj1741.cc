/*************************************************************************
    > File Name: poj1741.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com
    > Created Time: 2019年04月22日 星期一 15时18分01秒
 ************************************************************************/
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include <cstring>
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define P pair<int,int>
using namespace std;
const int N = 10100;
vector<P> E[N];
int size[N],MAX_SIZE[N],n,k,rt,S,ans;
bool vis[N];
vector<int> dis;
void dfsCenter(int u,int fa)
{
    size[u] = 1;  MAX_SIZE[u] = 0;
    for(int i = 0; i < E[u].size(); ++i) {
        int v = E[u][i].first;
        if(v == fa || vis[v]) continue;
        dfsCenter(v,u);
        size[u] += size[v];
        MAX_SIZE[u] = max(MAX_SIZE[u],size[v]); //最大子树的大小
    }
    MAX_SIZE[u] = max(MAX_SIZE[u], S - size[u]);
    if(!rt || MAX_SIZE[u] < MAX_SIZE[rt]) { //重心是以重心为根的最大子树最小
        rt = u;
    }
}

void dfsDis(int u,int fa,int res)
{
    dis.push_back(res);
    for(int i = 0; i < E[u].size(); ++i) {
        int w = E[u][i].second;
        int v = E[u][i].first;
        if(fa == v || vis[v]) continue;
        dfsDis(v, u, res + w);
    }
}

int cal(int u,int x)
{
    dis.clear();
    dfsDis(u,0,x);
    sort(dis.begin(), dis.end());
    int i = 0, j = (int)dis.size() - 1, ret = 0;
    while(i < j) {
        if(dis[i] + dis[j] <= k) {
            ret += j - i;
            i++;
        }else{
            j--;
        }
    }
    return ret;
}

void dfs(int u)
{
    ans += cal(u,0);
    vis[u] = 1;
    for(int i = 0; i < E[u].size(); ++i) {
        int v = E[u][i].first;
        int w = E[u][i].second;
        if(vis[v]) continue;
        ans -= cal(v,w);
        S = size[v];
        dfsCenter(v,rt = 0);
        dfs(rt);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    //ios::sync_with_stdio(false); cin.tie(0);
    int u,v,w;
    while(scanf("%d%d",&n,&k) == 2) {
        if(n == 0 && k == 0) break;
        for(int i = 0; i < N; ++i) {
            E[i].clear();
        }
        memset(vis, 0, sizeof vis);
        for(int i = 0; i < n - 1; ++i) {
            scanf("%d%d%d",&u,&v,&w);
            E[u].push_back(P(v,w));
            E[v].push_back(P(u,w));
        }
        S = n; ans = 0;
        dfsCenter(1, rt = 0);
        dfs(rt);
        printf("%d\n",ans);
    }
    return 0;
}

