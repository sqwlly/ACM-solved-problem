/*************************************************************************
    > File Name: P1734.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年11月11日 星期日 19时06分17秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
int dp[1024], sum[1024];
int love(int s)
{
	int ret = 0;
	for(int i = 1; i  < s; ++i) {
		if(s % i == 0)
			ret += i;
	}
	return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int s;
	cin>>s;
	dp[1] = 0;
	for(int i = 2; i <= s; ++i) {
		sum[i] = love(i);
	}
	for(int i = 1; i <= s; ++i) {
		for(int j = 1; j <= s; ++j) {
			if(i >= j)
			dp[i] = max(dp[i - j] + sum[j],dp[i]);
		}
	}
	cout<< dp[s] <<endl;
    return 0;
}
