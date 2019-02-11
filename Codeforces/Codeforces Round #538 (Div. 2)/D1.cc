/*************************************************************************
    > File Name: D1.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com
    > Created Time: 2019年02月11日 星期一 13时49分06秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 5010;
int dp[N][N], a[N];
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
#endif
    int n, x, d = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> x;
        if (a[d] != x) a[++d] = x;
    }
    n = d;
    for (int i = 2; i <= n; ++i) {
        for (int l = 1; l + i - 1 <= n; ++l) {
            int r = i + l - 1;
            if (a[r] == a[l])
                dp[l][r] = dp[l + 1][r - 1] + 1;
            else
                dp[l][r] = min(dp[l + 1][r], dp[l][r - 1]) + 1;
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}
