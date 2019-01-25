/*************************************************************************
    > File Name: F.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com
    > Created Time: 2019年01月25日 星期五 13时32分13秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
const int mod = 1e9+7;
long long dp[16][16][1 << 16]; //前i个数末尾位置为j使用情况为S的方案数
bool ok(int a, int b)
{
    if(a == b * 2 || b == a * 2)
        return 1;
    return 0;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
#endif
    int n;
    string s;
    //1324
    //1342
    //3412
    //4312
    //4321
    //3142
    cin >> n >> s;
    //dp[i][j][k] += dp[i - 1][num == j * 2 | j == num * 2][{S} | num]
    for (int i = 1; i <= n; ++i) {
        dp[1][i][(1 << i - 1)] = 1;
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int k = 1; k <= n; ++k) {
                if (j != k && s[i - 1] - '0' == ok(j, k))
                    for (int S = 0; S < (1 << n); ++S) {
                        if ((S & (1 << k - 1)) == 0) {
                            dp[i + 1][k][S | (1 << k - 1)] = (dp[i + 1][k][S | (1 << k - 1)] + dp[i][j][S]) % mod;
                        }
                    }
            }
        }
    }
    long long ans = 0;
    for (int j = 1; j <= n; ++j) {
        ans = (ans + dp[n][j][(1 << n) - 1]) % mod;
    }
    cout << ans << endl;
    return 0;
}

