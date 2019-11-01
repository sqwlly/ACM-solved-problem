/*************************************************************************
    > File Name: I.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年10月12日 星期六 12时14分01秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(args...)                                   \
    do{                                                \
	        cout << "\033[32;1m" << #args << " -> ";   \
         err(args);                                    \
      } while(0)                                       
#else
#define dbg(...)
#endif
void err()
{
    cout << "\033[39;0m" << endl;
}
template <template <typename...> class T, typename t, typename... Args>
void err(T<t> a, Args... args)
{
    for (auto x : a) cout << x << ' ';
    err(args...);
}
template <typename T, typename... Args>
void err(T a, Args... args)
{
    cout << a << ' ';
    err(args...);
}
/****************************************************************************************************/
constexpr int INF = INT_MAX, N = 2000;
struct Edge {
    Edge() {}
    Edge(int from, int to, int cap, int flow) : from(from), to(to), cap(cap), flow(flow) {}
    int from, to, cap, flow;
};
struct Dinic {
    int n, m, s, t;
    vector <Edge> edges;
    vector<int> G[N];
    bool vis[N];
    int d[N];
    int cur[N];

    void init(int n, int s, int t) {
        this->n = n, this->s = s, this->t = t;
        for (int i = 0; i <= n; i++) G[i].clear();
        edges.clear();
    }

    int add_edge(int from, int to, int cap) {
        edges.push_back(Edge(from, to, cap, 0));
        edges.push_back(Edge(to, from, 0, 0));
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
        return m - 2;
    }

    bool BFS() {
        memset(vis, 0, sizeof(vis));
        queue<int> Q;
        Q.push(s);
        d[s] = 0;
        vis[s] = true;
        while (!Q.empty()) {
            int x = Q.front();
            Q.pop();
            for (int i = 0; i < (int) G[x].size(); i++) {
                Edge &e = edges[G[x][i]];
                if (!vis[e.to] && e.cap > e.flow) {
                    vis[e.to] = true;
                    d[e.to] = d[x] + 1;
                    Q.push(e.to);
                }
            }
        }
        return vis[t];
    }

    int DFS(int x, int a) {
        if (x == t || a == 0)return a;
        int flow = 0, f;
        for (int &i = cur[x]; i < (int) G[x].size(); i++) {
            Edge &e = edges[G[x][i]];
            if (d[x] + 1 == d[e.to] && (f = DFS(e.to, min(a, e.cap - e.flow))) > 0) {
                e.flow += f;
                edges[G[x][i] ^ 1].flow -= f;
                flow += f;
                a -= f;
                if (a == 0) break;
            }
        }
        return flow;
    }

    int max_flow() {
        int flow = 0;
        while (BFS()) {
            memset(cur, 0, sizeof(cur));
            flow += DFS(s, INF);
        }
        return flow;
    }
} f;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,m,k;
	cin >> n >> m >> k;
	f.init(n + m + 3, 1, n + m + 3);
	int s1 = 1, s2 = 2;
	f.add_edge(s1, s2, k);
	for(int i = 1, t, x; i <= n; ++i) {
		cin >> t;
		f.add_edge(s1, s2 + i, 1);
		f.add_edge(s2, s2 + i, 1);
		for(int j = 1; j <= t; ++j) {
			cin >> x;
			f.add_edge(s2 + i, s2 + n + x, 1);
		}
	}
	for(int i = 1; i <= m; ++i) {
		f.add_edge(i + s2 + n, s2 + n + m + 1, 1);
	}
	cout << f.max_flow() << '\n';
    return 0;
}
