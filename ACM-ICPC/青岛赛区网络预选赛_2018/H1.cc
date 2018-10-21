/*************************************************************************
    > File Name: H1.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年10月21日 星期日 22时24分56秒
 ************************************************************************/

#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
char s[100010];
LL dp[100010][2];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int T;
	cin>>T;
	while(T--){
		scanf("%s",s+1);
		int n = strlen(s+1);
		if(s[n] == '1') {
			dp[n][1] = 1;
			dp[n][0] = 2;
		}else{
			dp[n][1] = 2;
			dp[n][0] = 1;
		}
		for(int i = n - 1; i >= 1; --i){
			if(s[i] == '0') {
				dp[i][1] = dp[i + 1][1] + (n - i + 1) * 2;
				dp[i][0] = dp[i + 1][1] + (n - i + 1) * 1;
			}else{
				dp[i][1] = dp[i + 1][0] + (n - i + 1) * 1;
				dp[i][0] = dp[i + 1][0] + (n - i + 1) * 2;
			}
		}
		LL ans = 0;
		for(int i = 1; i <= n; ++i){
			ans += dp[i][1];
		}
		printf("%lld\n",ans);
	}

    return 0;
}
