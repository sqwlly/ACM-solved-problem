/*************************************************************************
    > File Name: poj3420.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com
    > Created Time: 2018年12月01日 星期六 11时06分27秒
 ************************************************************************/

#include<iostream>
#include<cstring>
typedef long long LL;
using namespace std;
const int NUM = 4,MAXN = 4;
int mod, dp[4] = {1,1,5,11};
struct Matrix//矩阵的类
{
    LL a[NUM][NUM];
    Matrix() {}
    Matrix(LL *t)
    {
        int k = 0;
        for(int i = 0; i < NUM; ++i)
            for(int j = 0; j < NUM; ++j)
                a[i][j] = t[k++];
    }
    void init()           //将其初始化为单位矩阵
    {
        memset(a, 0, sizeof(a));
        for (int i = 0; i < MAXN; i++)
            a[i][i] = 1;
    }
};

Matrix mul(Matrix A,Matrix B)  //(a*b)%mod  矩阵乘法
{
    Matrix ans;
    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++) {
            ans.a[i][j] = 0;
            for (int k = 0; k < MAXN; k++)
                ans.a[i][j] = (ans.a[i][j] + A.a[i][k] * B.a[k][j] + mod) % mod;
        }
    return ans;
}

LL solve(int n)
{
    LL t[16] = {1,5,1,-1,1,0,0,0,0,1,0,0,0,0,1,0};
    Matrix ans, A(t);
    ans.init();
    while(n > 0) {
        if(n & 1) ans = mul(ans,A);
        A = mul(A,A);
        n >>= 1;
    }
    LL ret = 0;
    for(int i = 0; i < 4; ++i)
        ret = (ret + ans.a[0][3 - i] * dp[i]) % mod;
    return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    int n;
    //  [1 5 1 -1] ^ (n - 3) [1 ] =  [dp[n]    ] dp[n - 1]
    //  [1 0 0  0]			 [1 ]    [dp[n - 1]] dp[n - 2]
    //  [0 1 0  0]			 [5 ]    [dp[n - 2]] dp[n - 3]
    //  [0 0 1  0]			 [11]    [dp[n - 3]] dp[n - 4]
    //  dp[n] = dp[n - 1] + 5 * dp[n - 2] + dp[n - 3] + dp[n - 4];
    //  dp[n - 1] = dp[n - 1]
    //  dp[n - 2] = dp[n - 2]
    //  dp[n - 3] = dp[n - 3]
    while(cin >> n >> mod && (mod + n)) {
        if(n < 4) {
            cout << dp[n] % mod << endl;
        }else{
            cout << solve(n - 3) << endl;
        }
    }

    return 0;
}

