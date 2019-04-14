/*************************************************************************
    > File Name: 1003.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年04月13日 星期六 20时06分27秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 2E3;
int dp[N][N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int T,n,m,k,a,b,c;
	cin >> T;
	while(T--) {
		cin >> n >> m >> k >> a >> b >> c;
		int man = n + k;
		int woman = m + k;
	//	dp[i][j] = max(dp[i - 2][j] + min(a,b), dp[i - 1][j - 1] + c);
		memset(dp,0x3f,sizeof dp);
		dp[0][0] = 0;
		for(int i = 0; i <= man; ++i) {
			for(int j = 0; j <= woman; ++j) {
				if(i - 1 >= 0) {
					dp[i][j] = min(dp[i][j],dp[i - 1][j] + min(a,b));
				}
				if(j - 1 >= 0) {
					dp[i][j] = min(dp[i][j],dp[i][j - 1] + min(a,b));
				}
				if(i - 1 >= 0 && j - 1 >= 0) {
					dp[i][j] = min(dp[i][j],min(dp[i - 1][j - 1] + c, dp[i - 1][j - 1] + min(a,b) * 2));
				}
				if(i - 2 >= 0) {
					dp[i][j] = min(dp[i][j],dp[i - 2][j] + min(a,b));
				}
				if(j - 2 >= 0) {
					dp[i][j] = min(dp[i][j],dp[i][j - 2] + min(a,b));
				}
				if(i - 2 >= 0 && j - 1 >= 0) {
					dp[i][j] = min(dp[i][j],min(dp[i - 2][j - 1] + min(a,b) * 2, dp[i - 2][j - 1] + c + min(a,b)));
				}
				if(j - 2 >= 0 && i - 1 >= 0) {
					dp[i][j] = min(dp[i][j],min(dp[i - 1][j - 2] + min(a,b) * 2, dp[i - 1][j - 2] + c + min(a,b)));
				}
				if(i - 3 >= 0 && j - 1 >= 0) {
					dp[i][j] = min(dp[i][j],min(dp[i - 3][j - 1] + b + min(a,b), dp[i - 3][j - 1] + c + min(a,b)));
				}else if(i - 3 >= 0 && j == 0){
					dp[i][j] = min(min(dp[i][j],dp[i - 3][j] + b),dp[i - 3][j] + 3 * a);
				}
				if(j - 3 >= 0 && i - 1 >= 0) {
					dp[i][j] = min(dp[i][j],min(dp[i - 1][j - 3] + b + min(a,b), dp[i - 1][j - 3] + c + min(a,b)));
				}else if(j - 3 >= 0 && i == 0) {
					dp[i][j] = min(min(dp[i][j],dp[i][j - 3] + b),dp[i][j - 3] + 3 * a);
				}
			}
		}
		cout << dp[man][woman] << endl;
	}
    return 0;
}
