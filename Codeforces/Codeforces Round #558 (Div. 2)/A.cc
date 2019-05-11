#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define P pair<int,int>
using namespace std;
const int N = 3E5+10;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m;
    cin >> n >> m;
    int ans = 0;
    if(m * 2 > n) {
        ans = n - m;
    }else{
        ans = max(1,m);
    }
    cout << ans << endl;
    return 0;
}
