/*************************************************************************
    > File Name: P1315.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年10月15日 星期二 10时47分31秒
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
constexpr int N = 1E4+10, M = N * 10,INF = INT_MAX;
struct Edge {
    int from, to, cap, flow, cost;
    Edge() {}
    Edge(int f, int t, int c, int fl, int co) : from(f), to(t), cap(c), flow(fl), cost(co) {}
};

struct MCMF {
    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G[N];
    bool inq[N];
    int d[N];
    int p[N];
    int a[N];

    void init(int n, int s, int t) {
        this->n = n, this->s = s, this->t = t;
        edges.clear();
        for (int i = 0; i < n; ++i) G[i].clear();
    }

    int add_edge(int from, int to, int cap, int cost) {
        edges.push_back(Edge(from, to, cap, 0, cost));
        edges.push_back(Edge(to, from, 0, 0, -cost));
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
        return m - 2;
    }

    bool BellmanFord(int &flow, int &cost) {
        for (int i = 0; i < n; ++i) d[i] = INF;
        memset(inq, 0, sizeof(inq));
        d[s] = 0, a[s] = INF, inq[s] = true, p[s] = 0;
        queue<int> Q;
        Q.push(s);
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            inq[u] = false;
            for (int i = 0; i < G[u].size(); ++i) {
                Edge &e = edges[G[u][i]];
                if (e.cap > e.flow && d[e.to] > d[u] + e.cost) {
                    d[e.to] = d[u] + e.cost;
                    p[e.to] = G[u][i];
                    a[e.to] = min(a[u], e.cap - e.flow);
                    if (!inq[e.to]) {
                        Q.push(e.to);
                        inq[e.to] = true;
                    }
                }
            }
        }
        if (d[t] == INF) return false;
        flow += a[t];
        cost += a[t] * d[t];
        int u = t;
        while (u != s) {
            edges[p[u]].flow += a[t];
            edges[p[u] ^ 1].flow -= a[t];
            u = edges[p[u]].from;
        }
        return true;
    }

    int min_cost() {
        int flow = 0, cost = 0;
        while (BellmanFord(flow, cost));
        return cost;
    }
} mf;

int D[N],mx[N],t[M],a[M],b[M],rec[N],off[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,m,k;
	cin >> n >> m >> k;
	for(int i = 1; i < n; ++i) {
		cin >> D[i];
	}
	for(int i = 1; i <= m; ++i) {
		cin >> t[i] >> a[i] >> b[i];
		off[b[i]]++;
		mx[a[i]] = max(mx[a[i]], t[i]);
	}
	long long ans = 0;
	for(int i = 1; i < n; ++i) {
		rec[i + 1] = max(rec[i], mx[i]) + D[i];
	}
	for(int i = 1; i <= m; ++i) {
		ans += rec[b[i]] - t[i];
	}
	int S1 = 1, S2 = 2, T = n * 2 + 2;
	mf.init(n * 2 + 4, S1, T);
	mf.add_edge(S1, S2, k, 0);
	for(int i = 1; i < n; ++i) {
		mf.add_edge(S2, S2 + n + i, D[i], 0);
		mf.add_edge(S2 + i, S2 + n + i, max(rec[i] - mx[i],0), 0);
		mf.add_edge(S2 + n + i, S2 + i + 1, INF, -off[i + 1]);
		mf.add_edge(S2 + i + 1, T, INF, 0);
	}
	cout << ans + mf.min_cost() << endl;
    return 0;
}
