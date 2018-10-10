/*************************************************************************
    > File Name: G.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年10月04日 星期四 13时25分48秒
 ************************************************************************/

#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
const int N = 3e5+10, mod = 1e9+7;
LL a[N],sum[N],w[N],SUM[N],rev[N];

int main()
{
#ifndef ONLINE_JUDGE
#endif
	int n;
	cin>>n;
	for(int i = 1; i <= n; ++i){
		cin>>a[i];
		sum[i] = sum[i - 1] + a[i];
		SUM[i] = SUM[i - 1] + sum[i];
	}
	for(int i = n; i >= 1; --i){
		rev[i] = rev[i + 1] + sum[i];
	}
	for(int i = 1; i <= n; ++i)
		cin>>w[i];
	LL ans = 0;
	for(int i = 1; i <= n; ++i){
		ans = (ans + (SUM[n] - SUM[n - i] - SUM[i - 1]) * w[i] % mod) % mod;
	}
	cout<<(ans + mod) % mod<<endl;
    return 0;
}
