/*************************************************************************
    > File Name: L3_020.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月03日 星期日 09时24分52秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 1E6+10;
int dp[N][4];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	string s;
	cin >> s;
	//dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
	for(int i = 1; i < s.length(); ++i) {
		dp[i][0] = 1;
		for(int j = 1; j <= 3; ++j) {
			if(s[i] == s[i - 1]) {
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j] - dp[i - 2][j - 1];
			}else{
			
			}
		}
	}
    return 0;
}
