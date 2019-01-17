/*************************************************************************
    > File Name: P2476.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年01月17日 星期四 13时47分16秒
 ************************************************************************/

#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
const int mod = 1e9+7;
LL dp[16][16][16][16][16][6], num[6];

LL rec(int a,int b,int c,int d,int e,int last)
{
	if((a | b | c | d | e) == 0) return 1;
	if(dp[a][b][c][d][e][last]) return dp[a][b][c][d][e][last];
	LL sum = 0;
	if(a) sum += (a - (last == 2)) * rec(a - 1, b, c, d, e, 1), sum %= mod;
	if(b) sum += (b - (last == 3)) * rec(a + 1, b - 1, c, d, e, 2), sum %= mod;
	if(c) sum += (c - (last == 4)) * rec(a, b + 1, c - 1, d, e, 3), sum %= mod;
	if(d) sum += (d - (last == 5)) * rec(a, b, c + 1, d - 1, e, 4), sum %= mod;
	if(e) sum += e * rec(a, b, c, d + 1, e - 1, 5), sum %= mod;
	return dp[a][b][c][d][e][last] = sum;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int k, x;
	cin >> k;
	for(int i = 0; i < k; ++i) {
		cin >> x;
		num[x]++;
	}
	cout << rec(num[1], num[2], num[3], num[4], num[5], 0) << endl;
    return 0;
}
