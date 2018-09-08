#include <bits/stdc++.h>
using namespace std;
const int Maxn = 10010, INF = 1e9 + 7;
struct node {
        int to, val;
        node() {
        }
        node(int a, int b) {
                to = a;
                val = b;
        }
};

vector<node> adj[Maxn], _adj[Maxn];

bool vis[Maxn];
int dis[Maxn], n, m, k;

void AddEdge(int x, int y, int val) {
        adj[x].push_back(node(y, val));
        _adj[y].push_back(node(x, val)); //把图反向
}
void Dijkstra(int s, int t) {
        priority_queue<int, vector<int>, greater<int> > q;
        while (!q.empty())
                q.pop();

        for (int i = 1; i <= n; i++)
                vis[i] = false, dis[i] = INF;
        vis[t] = true;
        dis[t] = 0;
        q.push(t);

        int u, len;
        while (!q.empty()) {
                u = q.top();
                q.pop();
                len = _adj[u].size();
                for (int i = 0; i < len; i++) {
                        node v = _adj[u][i];
                        if (dis[v.to] > dis[u] + v.val) {
                                dis[v.to] = dis[u] + v.val;
                                if (!vis[v.to]) {
                                        q.push(v.to);
                                        vis[v.to] = true;
                                }
                        }
                }
                vis[u] = false;
        }
}

struct Anode {
        int h, g, id;
        Anode(int a, int b, int c) {
                h = a;
                g = b;
                id = c;
        }
        bool operator<(Anode a) const {
                return h + g > a.h + a.g;
        }
};

priority_queue<Anode> pq;

int BFS(int s, int t, int limit) {
        while (!pq.empty())
                pq.pop();
        pq.push(Anode(0, dis[s], s));

        int len, num;
        num = 0;
        while (!pq.empty()) {
                Anode u = pq.top();
                pq.pop();
                if (u.id == t)
                        ++num;
                if (u.h > limit)
                        return -1;
                if (num >= k)
                        return u.h;

                len = adj[u.id].size();
                for (int i = 0; i < len; i++) {
                        node v = adj[u.id][i];
                        if (dis[v.to] > limit)
                                continue;
                        pq.push(Anode(u.h + v.val, dis[v.to], v.to));
                }
        }

        return -1;
}

int main() {
        while (~scanf("%d%d", &n, &m)) {

                int x, y, v, s, t, limit;
                for (int i = 0; i < Maxn; i++)
                        adj[i].clear(), _adj[i].clear();
                scanf("%d%d%d%d", &s, &t, &k, &limit);
                for (int i = 1; i <= m; i++) {
                        scanf("%d%d%d", &x, &y, &v);
                        AddEdge(x, y, v);
                }
                if (s == t)
                        k++;
                Dijkstra(s, t);
                int ans = BFS(s, t, limit);
                if (ans > limit || ans == -1)
                        printf("Whitesnake!\n");
                else {
                        printf("yareyaredawa\n");
                }
        }
        return 0;
}
