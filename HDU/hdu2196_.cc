/**==========================================
 *   This is a solution for ACM/ICPC problem
 *
 *   @author: shuangde
 *   @blog: blog.csdn.net/shuangde800
 *   @email: zengshuangde@gmail.com
 *===========================================*/
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
#include<cstring>
using namespace std;
 
typedef long long int64;
const int INF = 0x3f3f3f3f;
const double PI  = acos(-1.0);
 
const int MAXN = 10010;
 
struct Node{
    int v, w;
};
 
vector<Node>adj[MAXN];
 
int indeg[MAXN];
int val[MAXN];
int n, m;
int64 f[MAXN][2];
int vis[MAXN];
 
int64 dfs1(int u){
    vis[u] = true;
    f[u][0] = 0;
    for(int i=0; i<adj[u].size(); ++i){
        int v = adj[u][i].v;
        int w = adj[u][i].w;
        if(vis[v]) continue;
        f[u][0] = max(f[u][0], dfs1(v)+w);
    }
    return f[u][0];
}
 
 
void dfs2(int u, int fa_w){
    vis[u] = true;
 
    int max1=0, v1, max2=0, v2;
 
    for(int i=0; i<adj[u].size(); ++i){
        int v = adj[u][i].v;
        int w = adj[u][i].w;
        if(vis[v]) continue;
        int tmp = f[v][0] + w;
        if(tmp > max1){
            max2 = max1; v2 = v1;
            max1 = tmp; v1 = v;
        }else if(tmp == max1 || tmp>max2){
            max2 = tmp;
            v2 = v;
        }
    }
 
    if(u != 1){ 
        int tmp = f[u][1];
        int v = -1;
        if(tmp > max1){
            max2 = max1; v2 = v1;
            max1 = tmp; v1 = v;
        }else if(tmp == max1 || tmp>max2){
            max2 = tmp;
            v2 = v;
        }
    }
 
    for(int i=0; i<adj[u].size(); ++i){
        int v = adj[u][i].v;
        int w = adj[u][i].w;
        if(vis[v]) continue;
        if(v==v1){
            f[v][1] = max2 + w;
        }else{
            f[v][1] = max1 + w; 
        }
        dfs2(v, w);
    }
}
 
int main(){
 
    while(~scanf("%d", &n) && n){
 
        for(int i=1; i<=n; ++i) adj[i].clear();
 
        for(int u=2; u<=n; ++u){
            int v, w;
            scanf("%d%d", &v, &w);
            adj[u].push_back((Node){v, w});
            adj[v].push_back((Node){u, w});
        }
        
        memset(f, 0, sizeof(f));
 
        memset(vis, 0, sizeof(vis));
        dfs1(1);
 
        memset(vis, 0, sizeof(vis));
        dfs2(1, 0);
 
        for(int i=1; i<=n; ++i){
            cout << max(f[i][0], f[i][1]) << endl;
        }
    }
 
    return 0;
}

