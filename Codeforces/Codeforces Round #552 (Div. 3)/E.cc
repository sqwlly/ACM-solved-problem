/*************************************************************************
    > File Name: E.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com
    > Created Time: 2019年04月17日 星期三 10时52分04秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define P pair<int,int>
using namespace std;
const int N = 2E5+10;
int f[N],vc[N];
map<int,P> pos;
bool vis[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
    int n,k,w;
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) {
        cin >> w;
        vc[w] = i;
        pos[i] = make_pair(i - 1, i + 1);
    }
    for(int i = 1; i <= n + 2; ++i) f[i] = i;
    int cur = 0;
    for(int i = n; i >= 1; --i) {
        if(vis[vc[i]] == 1) continue;
        vis[vc[i]] = 1;
        f[vc[i]] = n + 1 + cur;
        P p = make_pair(n + 2, -2);  //记录被标记连续区间的最左端和最右端
        vector<int> t = {vc[i]};
        //然后遇到一个连续被标记区间里的点的时候就可以直接跳到区间端点
        for(int l = 1, d = 1, x = vc[i] + l; d <= k && x <= n; x = pos[x].second) { 
            if(vis[x]) {
                continue;
            }
            p.second = max(x + 1, p.second);
            ++d;
            vis[x] = 1;
            f[x] = n + 1 + cur;
            t.push_back(x);
        }
        for(int r = 1, d = 1, y = vc[i] - r; d <= k && y >= 1; y = pos[y].first) {
            if(vis[y]) {
                continue;
            }
            p.first = min(y - 1, p.first);
            ++d;
            vis[y] = 1;
            f[y] = n + 1 + cur;
            t.push_back(y);
        }
        if(p.first == n + 2) p.first = 0;
        if(p.second == -2) p.second = n + 1;
        for(int i = 0; i < t.size(); ++i) {
            pos[t[i]] = p;
        }
        cur ^= 1;
    }
    for(int i = 1; i <= n; ++i) {
        cout << f[i] - n;
    }
    return 0;
}

