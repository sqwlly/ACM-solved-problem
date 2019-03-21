/*************************************************************************
    > File Name: G.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com
    > Created Time: 2019年03月21日 星期四 09时00分50秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define P pair<int,int>
using namespace std;
const int N = static_cast<const int>(2E5 + 10);
vector<P> E[N];
map<int,int> deg;

vector<P> vc;
int n,k,MAX,col[N];

void dfs(int u,int fa,int color)
{
    for(const auto &i : E[u]) {
        int v = i.first, idx = i.second;
        if(v == fa) continue;
        col[idx] = color;
        dfs(v, u, (color + 1) % MAX);
        color = (color + 1) % MAX;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
    int u,v;
    cin >> n >> k;
    for(int i = 0; i < n - 1; ++i) {
        cin >> u >> v;
        E[u].emplace_back(P(v,i));
        E[v].emplace_back(P(u,i));
        deg[u]++, deg[v]++;
    }
    for(const auto &i : deg) vc.emplace_back(i);
    sort(vc.begin(), vc.end(), [](const pair<int,int> &x, const pair<int,int> &y) ->int {
        return x.second > y.second;
    });
    MAX = vc[k].second;
    dfs(vc[k].first,0, 0);
    cout << MAX << endl;
    for(int i = 0; i < n - 1; ++i) {
        cout << col[i] + 1 << ' ';
    }
    return 0;
}

