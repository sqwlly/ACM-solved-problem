#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
typedef long long ll;
const int n = 3, md = 1E9 + 7;
ll mod= 1E9 + 7;
char bigint[2000001];
int len;
void divide2() {
    int temp = 0;
    for (int i = 0; i < len; i++) {
        temp = bigint[i] - '0';
        if (temp & 1) bigint[i + 1] += 10;
        bigint[i] = temp / 2+'0';
    }
}
void minus1() {
    if (bigint[len - 1] != '0')
        bigint[len - 1] -= 1;
    else {
        int k = len - 1;
        while (bigint[k] == '0') {
            bigint[k] = '9';
            k--;
        }
        bigint[k]--;
    }
}
int iseven() {
    if ((bigint[len - 1] - '0') % 2 == 1) return 1;
    else return 0;
}
int iszero() {
    for (int i = 0; i < len; i++)
        if (bigint[i] - '0') return 1;
    return 0;
}
struct Matrix
{
    ll m[n][n];
};
 
Matrix mul(Matrix a, Matrix b) //矩阵乘法模板
{
    Matrix ans;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ans.m[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                ans.m[i][j] = (ans.m[i][j] + a.m[i][k] * b.m[k][j] % mod) % mod;
            }
            // ans.m[i][j] %= md;
        }
    }
    return ans;
}
 
Matrix quickPow(Matrix a, ll b) //快速幂模板（只不过这里是矩阵快速幂）
{
    Matrix ans = { //单位矩阵
        1,0,0,
        0,1,0,
        0,0,1
    };
    Matrix tmp = a;
    while (iszero()) {
        if (iseven()) {
            ans = mul(ans, tmp);
            minus1();
        }
             
        tmp = mul(tmp, tmp);
        divide2();
    }
    return ans;
}
// fn = a * fn-1 + b * fn-2
/* [fn]        = [a b] [fn-1]
 * [fn-1]        [1 0] [fn-2]
 *
 * [fn-1]      = [a b] [fn-2]
 * [fn-2]        [1 0] [fn-3]
 *
 * [fn]        = [a b]^n - 1 [f1]
 * [fn-1]        [1 0]       [f0]
 * */
 
 // A ^ k % mod,
int f[1000];
int main()
{
    ll n;
    int x0, x1, a, b;
    cin >> x0 >> x1 >> a >> b;
    Matrix A = {
        a,b,1,
        1,0,0,
        0,0,1
    };
    cin >> bigint >> mod;
    len = strlen(bigint);
    minus1();
    Matrix tmp = quickPow(A,1234); //a^(n-1)
    cout << (tmp.m[0][0] * x1 + tmp.m[0][1] * x0)%mod << endl; //Fn
    f[0] = x0; f[1] = x1;
    //for (int i = 2; i <= n; ++i) {
    //  f[i] = f[i - 1] * a + f[i - 2] * b;
    //}
    //cout << f[n] << endl;
    return 0;
}
