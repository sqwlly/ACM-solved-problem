/*************************************************************************
    > File Name: C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年11月23日 星期五 01时21分36秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;

vector<int> v[100];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	for(int i = 1; i <= n; ++i) {
		dp[i] = 1;
	}
	for(int i = 1; i <= n; ++i) {
		int cnt = 0;
		for(int j = 1; j <= n; ++j) {
			if(a[j] % i == 0) {
				cnt++;
			}
		}
		ans *= cnt;
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			if(a[j])
		}
	}
	// 2
	// 1 3 4
	// {1} {1,3} {1,2}
	// {1} {3} {4} {1,4}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j < v[i].size(); ++j) {
			if(v[i][j])
		}
	}
	dp[0] = 0;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= i; ++j) {
			if(a[j])
		}
	}
    return 0;
}
