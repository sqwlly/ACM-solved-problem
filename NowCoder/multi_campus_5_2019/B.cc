#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N = 2,md = 1E9+7;

struct Matrix
{
    ll m[N][N];
};

Matrix mul(Matrix a, Matrix b) //矩阵乘法模板 
{
    Matrix ans;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            ans.m[i][j] = 0;
            for(int k = 0; k < N; k++)
            {
                ans.m[i][j] = (ans.m[i][j] + a.m[i][k]*b.m[k][j] % md) % md;
            }
           // ans.m[i][j] %= md;
        }
    }
    return ans;
}

Matrix quickPow(Matrix a, ll b) //快速幂模板（只不过这里是矩阵快速幂） 
{
    Matrix ans = { //单位矩阵
        1,0,
        0,1
    }; 
    Matrix tmp = a;
    while(b) {
        if(b&1)
            ans = mul(ans,tmp);
        tmp = mul(tmp,tmp);
        b >>= 1;
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
ll f[1000];
int main()
{
    ll n;
	ll x0,x1,a,b;
	cin >> x0 >> x1 >> a >> b;
    Matrix A = {
        a,b,
        1,0
    };
	cin >> n;
    Matrix tmp = quickPow(A,n - 1); //a^(n-1)
    cout<< tmp.m[0][0] * x1 + tmp.m[0][1] * x0 << endl; //Fn 
	f[0] = x0; f[1] = x1;
	for(int i = 2; i <= n; ++i) {
		f[i] = (f[i - 1] * a % md + f[i - 2] * b % md) % md;
	}
	cout << f[n] << endl;
    return 0;
}
