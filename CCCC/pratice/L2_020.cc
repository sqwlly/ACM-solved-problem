/*************************************************************************
    > File Name: L2_020.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com
    > Created Time: 2019年03月03日 星期日 13时29分42秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 1E5+10;
int a[N];
vector<int> E[N];
bool vis[N];
double ans,z,r;
void dfs(int rt,double sum)
{
    if(a[rt] != 0) {
        ans += sum * a[rt];
    }
    for(auto v : E[rt]){
        if(vis[v] == 0) {
            vis[v] = 1;
            dfs(v,sum * (1 - r / 100));
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
    int n,x,w,k;
    cin >> n >> z >> r;
    for(int i = 0; i < n; ++i) {
        cin >> k;
        if(k == 0) {
            cin >> a[i];
        }else{
            for(int j = 0; j < k; ++j) {
                cin >> x;
                E[i].push_back(x);
                E[x].push_back(i);
            }
        }
    }
    vis[0] = 1;
    dfs(0,z);
    cout << (int)ans << endl;
    return 0;
}

