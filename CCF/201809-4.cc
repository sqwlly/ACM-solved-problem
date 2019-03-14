/*************************************************************************
    > File Name: 201809-4.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com
    > Created Time: 2019年03月14日 星期四 13时56分45秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 302;
int a[N],b[N], n, ok;
bool vis[N][N][N];
void dfs(int cur,int c,int d)
{
    if(ok || vis[cur][c][d]) return;
    vis[cur][c][d] = 1;
    if(cur == n + 1 && ok == 0) {
        if((a[n] + a[n - 1]) / 2 == b[n]) {
            ok = 1;
            for(int i = 1; i <= n; ++i) {
                cout << a[i] << (i == n ? '\n' : ' ');
            }
        }
        return;
    }
    int r = 3 * b[cur - 1] - a[cur - 1] - a[cur - 2];
    for(int i = max(r,1); (a[cur - 1] + a[cur - 2] + i) / 3 <= b[cur - 1]; ++i) {
        int t = (a[cur - 1] + a[cur - 2] + i) / 3;
        if(t != b[cur - 1]) continue;
        a[cur] = i;
        dfs(cur + 1, a[cur], a[cur - 1]);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> b[i];
    for (int i = 1; i <= 2 * b[1] + 1; ++i) {
        int j = 2 * b[1] - i;
        a[1] = i, a[2] = j;
        dfs(3, a[2], a[1]);
        if (ok) break;
    }
    return 0;
}
