/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com
    > Created Time: 2019年03月01日 星期五 21时15分32秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
typedef long long LL;
const int N = 300 * 666, mod = 1e8 + 7;
LL dp[2][N * 10];
int a[N];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
    //dp[i][j] = dp[i - 1][j - a[i]] + dp[i - 1][-j]
    int n, cur = 0;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int dx = N + 666;
    dp[1][dx] = 1;
    for(int i = 1; i <= n; ++i) {
        for(int j = -N; j <= N; ++j) {
            if(j == 666) continue;
            dp[cur][j + dx] = (dp[cur ^ 1][j - a[i] + dx] + dp[cur ^ 1][-j + dx]) % mod;
        }
        cur ^= 1;
    }
    cout << dp[cur ^ 1][-666 + dx] << endl;
    return 0;
}

