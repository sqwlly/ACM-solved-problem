/*************************************************************************
    > File Name: C1.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年09月06日 星期五 10时54分01秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(args...)                                   \
    do{                                                \
	        cout << "\033[32;1m" << #args << " -> ";   \
         err(args);                                    \
      } while(0)                                       
#else
#define dbg(...)
#endif
void err()
{
    cout << "\033[39;0m" << endl;
}
template <template <typename...> class T, typename t, typename... Args>
void err(T<t> a, Args... args)
{
    for (auto x : a) cout << x << ' ';
    err(args...);
}
template <typename T, typename... Args>
void err(T a, Args... args)
{
    cout << a << ' ';
    err(args...);
}
/****************************************************************************************************/
typedef long long LL;
LL dp[100][100];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	
	int mod,n,k;
	int T,w = 0;
	cin >> T;
	while(T--) {
		cin >> n >> k >> mod;
		if(n < k) k = n;
		dp[1][1] = 1;
		dp[2][1] = 2;
		for(int i = 2; i <= n; ++i) {
			dp[i][i] = dp[i - 1][i - 1] * i % mod;
		}
		LL num = 2, sum = 0, last = 0;
		for(int j = 1; j <= k; ++j) {
			sum = (dp[j][j] + j * last % mod) % mod;
			last = sum % mod;
			num = num * j % mod;
			for(int i = j + 1; i <= n; ++i) {
				dp[i][j] = (dp[i - 1][j] % mod + sum % mod) % mod;
				sum = (sum + num) % mod;
			}
		}
		cout << "Case #" << ++w << ": " << dp[n][k] % mod << '\n';
	}

    return 0;
}
