/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com
    > Created Time: 2019年01月26日 星期六 10时32分52秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
int dp[20][20][10010], T[20][20], dir[5][2] = {1,0,0,1,0,-1,-1,0,0},n,m;

void refresh(int x,int y,int t) {
    //上一个状态
    for (int i = 0; i < 5; ++i) { //四个方向 + 原地不动
        int tx = x + dir[i][0], ty = y + dir[i][1];
        if (tx >= 1 && tx <= n && ty >= 1 && ty <= m) {
            dp[x][y][t] = max(dp[x][y][t], dp[tx][ty][t - 1]);
        }
    }
    if (t % T[x][y] == 0)
        dp[x][y][t]++;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
#endif
    int C, sx, sy, ex, ey;
    cin >> n >> m >> C;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> T[i][j];
        }
    }
    memset(dp, -0x3f, sizeof dp);
    cin >> sx >> sy >> ex >> ey;
    dp[sx][sy][0] = 0;
    for (int t = 1; t < 10010; ++t) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                refresh(i, j, t);
                if (dp[ex][ey][t] >= C) {
                    cout << t << endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}

