/*************************************************************************
    > File Name: I.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com
    > Created Time: 2019年03月09日 星期六 21时52分46秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 1E5+10;
int low[N],dfn[N],idx,ret;
vector<int> E[N];
stack<int> st;
void tarjan(int u,int fa)
{
    low[u] = dfn[u] = ++idx;
    st.push(u);
    for(auto v : E[u]) {
        if(v == fa) continue;
        if(!dfn[v]) {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
        }else{
            low[u] = min(low[u], dfn[v]);
        }
        if(low[v] > dfn[u]) ret++;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m,u,v;
    cin >> n >> m;
    for(int i = 0; i < m; ++i) {
        cin >> u >> v;
        E[u].push_back(v);
        E[v].push_back(u);
    }
    tarjan(1,0);
    cout << m - ret << endl;
    return 0;
}

