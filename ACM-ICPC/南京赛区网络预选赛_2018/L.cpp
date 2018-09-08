/* @L.cpp 分层最短路
*  题解: https://blog.csdn.net/Eternally831143/article/details/82292039
*/
#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
const int N = 100010;
bool vis[N][11];
LL dist[N][11];
struct node {
    int x, k;
    LL v;

    node(int a, int b, LL v) : x(a), k(b), v(v) {}

    friend bool operator<(const node &a, const node &b) {
        return a.v > b.v;
    }
};
vector<node> E[N];

int main() {
    int T;
    //freopen("in.txt","r",stdin);
    scanf("%d", &T);
    while (T--) {
        memset(vis, 0, sizeof vis);
        int n, m, k, s, t, x, y, z;
        LL ans = 1e15;
        scanf("%d%d%d", &n, &m, &k);
        s = 0, t = n - 1;
        for (int i = 0; i <= n; ++i)
            E[i].clear();
        for (i = 0; i < m; i++) {
            scanf("%d%d%d", &x, &y, &z);
            x--, y--;
            E[x].push_back(node(y, 0, z));
        }
        priority_queue<node> q;
        memset(dist, 0x3f, sizeof(dist));
        dist[s][0] = 0;
        q.push((node) {s, 0, 0});
        while (!q.empty()) {
            node now = q.top();
            q.pop();
            if (vis[now.x][now.k])
                continue;
            vis[now.x][now.k] = 1;
            int len = E[now.x].size();
            for (int i = 0; i < len; ++i) {
                node nxt = E[now.x][i];
                if (dist[now.x][now.k] + nxt.v < dist[nxt.x][now.k]) { //当前层最短路
                    dist[nxt.x][now.k] = dist[now.x][now.k] + nxt.v;
                    q.push((node) {nxt.x, now.k, dist[nxt.x][now.k]});
                }
                if (dist[now.x][now.k] < dist[nxt.x][now.k + 1] && now.k < k) { //往底下一层
                    dist[nxt.x][now.k + 1] = dist[now.x][now.k];
                    q.push((node) {nxt.x, now.k + 1, dist[nxt.x][now.k + 1]});
                }
            }
        }
        for (i = 0; i <= k; i++) ans = min(ans, dist[t][i]);
        printf("%lld\n", ans);
    }
    return 0;
}
