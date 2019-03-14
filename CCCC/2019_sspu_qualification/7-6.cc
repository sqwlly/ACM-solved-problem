/*************************************************************************
    > File Name: 7-6.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com
    > Created Time: 2019年03月13日 星期三 20时31分26秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 1E5+10;
vector<int> E[N];
int a[N],w[N];
double z,r;
double ans = 0;
void dfs(int u,double sum)
{
    if(w[u]) {
        ans += sum * w[u];
       // return;
    }
    for(auto v : E[u]) {
        dfs(v, sum * (1.0 - r / 100.0));
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
    int n,x,k;
    cin >> n >> z >> r;
    for(int i = 0; i < n; ++i) {
        cin >> k;
        if(k == 0) cin >> w[i];
        for(int j = 0; j < k; ++j) {
            cin >> x;
            E[i].push_back(x);
        }
    }
    dfs(0,z);
    cout << (int)ans << endl;
    return 0;
}

