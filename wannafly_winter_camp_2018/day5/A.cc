/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com
    > Created Time: 2019年01月24日 星期四 13时49分36秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;

vector<int> e[2010];
int ans[1010][2];
bool vis[1010];
bool book[1010][1010];
void dfs(int cur,int cen) {
    int y = 0;
    for (int i = 0; i < e[cur].size(); ++i) {
        int nxt = e[cur][i];
        int tx = cen, ty = cen + y;
        if (vis[nxt]) continue;
        while (book[tx][ty]) {
            ty++;
        }
        book[tx][ty] = 1;
        vis[nxt] = 1;
        ans[nxt][0] = tx, ans[nxt][1] = ty;
        y++;
        dfs(nxt, cen + 1);
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
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    vis[1] = 1;
    ans[1][0] = 1, ans[1][1] = 1;
    dfs(1, 2);
    for(int i = 1; i <= n; ++i) {
        printf("%d %d\n",ans[i][0],ans[i][1]);
    }
    return 0;
}

