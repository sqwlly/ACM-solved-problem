/*************************************************************************
    > File Name: poj2441.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年11月22日 星期四 14时07分34秒
 ************************************************************************/
#include<iostream>
#include<bitset>

using namespace std;
const int N = 20;

int dp[1<<N];
bool like[N][N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n,m,k,a,b;
	cin >> n >> m;
	for(int i = 0; i < n; ++i) {
		cin >> k;
		for(int j = 0; j < k; ++j) {
			cin >> b;
			like[i][b - 1] = 1;
		}
	}
	for(int i = 0; i < m; ++i) {
		if(like[0][i]) dp[1 << i] = 1;
	}
	for(int i = 1; i < n; ++i)  {
		//枚举大小为i的子集
		for(int s = (1 << i) - 1, x, y; s < (1 << m); x = s & -s, y = s + x, s = ((s & ~y) / x >> 1) | y) {
			if(dp[s]) {
				for(int j = 0; j < m; ++j) {
					if(like[i][j] && !((s >> j) & 1)) {
						dp[s | (1 << j)] += dp[s];
					}
				}
			}
		}
	}
	int ret = 0;
	for(int bit = 0; bit < (1 << m); ++bit) 
		if(bitset<32>(bit).count() == n) 
			ret += dp[bit];
	cout << ret << endl;
    return 0;
}
