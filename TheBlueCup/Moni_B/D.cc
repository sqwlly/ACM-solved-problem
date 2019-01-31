/*************************************************************************
    > File Name: 1.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com
    > Created Time: 2019年01月31日 星期四 13时02分59秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
int n = 5, m = 5, dir[8][2] = {-2,-1, -2,1, -1,-2, -1,2, 1,-2, 1,2, 2,-1, 2,1};
bool vis[5][5];
struct horse
{
    int x,y;
};
vector<horse> v;
bool check()
{
    bool ok[5][5] = {0};
    for(int i = 0; i < v.size(); ++i) {
        for(int j = 0; j < 8; ++j) {
            int tx = v[i].x + dir[j][0];
            int ty = v[i].y + dir[j][1];
            ok[v[i].x][v[i].y] = 1;
            if(tx < 0 || tx >= n || ty < 0 || ty >= m)
                continue;
            ok[tx][ty] = 1;
        }
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if(ok[i][j] == 0)
                return 0;
        }
    }
    //for(int i = 0; i < v.size(); ++i)
    //    cout << v[i].x << ' ' << v[i].y << endl;
    return 1;
}
int d[8][2] = {0,1,1,0,-1,0,0,-1, 1,1, -1,1, -1,-1, 1,-1},ans = 100;
void dfs(int x,int y,int cnt)
{
    if(vis[x][y]) return;
    for(int i = 0; i < v.size(); ++i) {
        for(int j = 0; j < 4; ++j) {
            int tx = v[i].x + d[j][0];
            int ty = v[i].y + d[j][1];
            if(tx == x && ty == y) {
                return;
            }
        }
    }
    vis[x][y] = 1;
    v.push_back(horse{x,y});
    if(check()) {
        ans = min(ans,(int)v.size());
        return;
    }
    for(int i = 0; i < 8; ++i) {
        int tx = x + d[i][0];
        int ty = y + d[i][1];
        if(tx >=0 && tx < n && ty >= 0 && ty < m) {
            dfs(tx,ty, cnt + 1);
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    //  freopen("input.in","r",stdin);
#endif
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            dfs(i,j,0);
        }
    }
  //  dfs(0,0,0);
    cout << ans << endl;
    return 0;
}

