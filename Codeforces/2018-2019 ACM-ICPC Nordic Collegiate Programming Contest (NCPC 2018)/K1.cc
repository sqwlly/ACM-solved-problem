#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1000000 + 5;
const int MOD = (int)1e9 + 7;
int F[N], Finv[N], inv[N];
LL pow_mod(LL a, LL b, LL p){ 
    LL ret = 1;
    while(b){
        if(b & 1) ret = (ret * a) % p;
        a = (a * a) % p;
        b >>= 1;
    }
    return ret;
}
void init(){
    inv[1] = 1;
    for(int i = 2; i < N; i ++){
        inv[i] = (MOD - MOD / i) * 1ll * inv[MOD % i] % MOD;
    }
    F[0] = Finv[0] = 1;
    for(int i = 1; i < N; i ++){
        F[i] = F[i-1] * 1ll * i % MOD;
        Finv[i] = Finv[i-1] * 1ll * inv[i] % MOD;
    }
}
int comb(int n, int m){
    if(m < 0 || m > n) return 0;
    return F[n] * 1ll * Finv[n - m] % MOD * Finv[m] % MOD;
}
int main(){
    init();
    int T, n, m, k, ans, flag, temp;
	T = 1;
    for(int cas = 1; cas <= T; cas ++){
        scanf("%d%d", &n, &k);
		m = k;
        ans = k * pow_mod(k-1, n-1, MOD) % MOD;
        flag = -1;
        //计算容斥 
        for(int i = 1; i <= k-1; i ++){
            ans = (ans + 1ll * flag * comb(k, k-i) * (k-i) % MOD * pow_mod((k-i-1), n-1, MOD) % MOD) % MOD;
            flag = -flag;
        }
        //接下来计算C(m, k) 
        temp = Finv[k];
        for(int i = 1; i <= k; i ++){
            temp = 1ll * temp * (m-k+i) % MOD;
        }
        ans = ((1ll * ans * temp) % MOD + MOD) % MOD;
        cout << ans << endl;
    }
}
