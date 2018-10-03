#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
LL dp[65][65],cnt[65];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	for(int i = 0; i <= 65; ++i){
		for(int d = 0; d <= i+1; ++d){
			for(int k = 1; k <= i; ++k){
				cnt[k] = cnt[k - 1] + cnt[max(k - 1 - d,0)] + 1;
			}
			dp[i][d] = (1LL<<i-1) - 1 - cnt[max(i - d - 1,0)];
		}
	}
	for(int i = 0; i < 15; ++i){
		for(int j = 0; j <= i; ++j){
			printf("%lld%c",dp[i][j],j==i?'\n':' ');
		}
	}
	int n,d;
	cin>>n>>d;
	cout<<dp[n][d]<<endl;
    return 0;
}

