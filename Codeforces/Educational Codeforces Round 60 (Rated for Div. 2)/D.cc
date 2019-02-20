/*************************************************************************
    > File Name: D.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年02月19日 星期二 21时25分30秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
typedef long long LL;
using namespace std;
const int NUM = 101, mod = 1e9+7;
LL MAXN;
struct Matrix//矩阵的类
{
    LL a[NUM][NUM];

    void init()           //将其初始化为单位矩阵
    {
        memset(a, 0, sizeof(a));
        for (int i = 0; i < MAXN; i++)
            a[i][i] = 1;
    }
} A;

Matrix mul(Matrix a, Matrix b)
{
    Matrix ret;
    LL x;
    for(int i=0;i<MAXN;i++)
    {
        for(int j=0;j<n;j++)
        {
            x = 0;
            for(int k=0;k<n;k++)
            {
                x += ((LL)a.a[i][k] * b.a[k][j])%mod;
                ret.a[i][j] = x%mod;
            }
        }
    }
    return ret;
}

Matrix pow(Matrix a,LL n)    //(a^n)%mod  //矩阵快速幂
{
    Matrix ans;
    ans.init();
    while (n) {
        if (n & 1)//n&1
            ans = mul(ans, a);
        n >>= 1;
        a = mul(a, a);
    }
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	LL n,m;
	cin >> n >> m;
	MAXN = m;
	Matrix A, ans;
	ans.a[0][0] = ans.a[0][m - 1] = 1;
	for(int i = 1; i <= m; ++i) {
		ans.a[i][i - 1] = 1;
	}
	A = pow(ans,n);
	cout << A.a[0][0] << endl;
    return 0;
}
