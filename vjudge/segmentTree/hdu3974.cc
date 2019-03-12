/*************************************************************************
    > File Name: hdu3974.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com
    > Created Time: 2019年03月12日 星期二 08时02分40秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 5E4+10;
vector<int> E[N];
int tr[N << 2], f[N], st[N], ed[N], cnt;

void dfs(int u,int fa)
{
    st[u] = ++cnt;
    for(auto v : E[u]) {
        if(v == fa) continue;
        dfs(v, u);
    }
    ed[u] = cnt;
}

void pushdown(int rt)
{
    if(tr[rt] != -1) {
        tr[rt << 1] = tr[rt << 1 | 1] =  tr[rt];
        tr[rt] = -1;
    }
}

void build(int rt,int l,int r)
{
    tr[rt] = -1;
    if(l == r) {
        return;
    }
    int mid = l + r >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
}

void update(int rt,int l,int r,int x,int y,int v)
{
    if(x <= l && r <= y) {
        tr[rt] = v;
        return;
    }
    pushdown(rt);
    int mid = l + r >> 1;
    if(x <= mid) update(rt << 1, l, mid, x, y, v);
    if(y > mid) update(rt << 1 | 1, mid + 1, r, x, y, v);
}

int query(int rt,int l,int r,int x)
{
    if(l == x && r == x) {
        return tr[rt];
    }
    int mid = l + r >> 1;
    pushdown(rt);
    if(x <= mid)
        return query(rt << 1, l, mid, x);
    else
        return query(rt << 1 | 1, mid + 1, r, x);
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
    int T,n,u,v,m,t = 0;
    cin >> T;
    while(T--) {
        cin >> n;
        memset(f, 0, sizeof f);
        for(auto &i : E) i.clear();
        for(int i = 1; i < n; ++i) {
            cin >> u >> v;
            f[u] = v;
            E[u].push_back(v);
            E[v].push_back(u);
        }
        cnt = 0;
        for(int i = 1; i <= n; ++i) {
            if (f[i] == 0) {
                dfs(i, 0);
                break;
            }
        }
        build(1, 1, n);
        cin >> m;
        char c;
        cout << "Case #" << ++t << ':' << endl;
        while(m--) {
            cin >> c >> u;
            if(c == 'C') cout << query(1, 1, n, st[u]) << endl;
            else{
                cin >> v;
                update(1, 1, n, st[u], ed[u], v);
            }
        }
    }
    return 0;
}

