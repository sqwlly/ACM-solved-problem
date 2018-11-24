/*************************************************************************
    > File Name: poj3254.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年11月24日 星期六 10时29分37秒
 ************************************************************************/

#include<iostream>

using namespace std;
const int mod = 100000000;
int dp[13][1<<13], row[13], rec[1 << 13], N = 1 << 13, tot;

void init()
{
	//预处理所有可行的状态
	for(int i = 0; i < N; ++i) {
		if((i & i << 1) == 0) 
			rec[tot++] = i;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n,m,x;
	cin >> n >> m;
	init();
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			cin>>x;
			row[i] |= (x << j); //状态压缩
		}
	}
	//第一行
	for(int i = 0; i < tot; ++i) {
		if((row[0] & rec[i]) == rec[i]) {
			dp[0][i] = 1;
		}
	}
	for(int i = 1; i < n; ++i) {
		for(int j = 0; j < tot; ++j) { //枚举每行的状态
			if((row[i] & rec[j]) == rec[j]) {
				for(int k = 0; k < tot; ++k) { //上一行的状态
					if((rec[j] & rec[k]) == 0) { //如果不冲突
						dp[i][j] = (dp[i][j] + dp[i - 1][k]) % mod;
					}
				}
			}
		}
	}
	int ans = 0;
	for(int i = 0; i < tot; ++i) {
		ans = (ans + dp[n - 1][i]) % mod;
	}
	cout << ans << endl;
    return 0;
}
