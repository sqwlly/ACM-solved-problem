/*************************************************************************
    > File Name: I.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年01月31日 星期四 10时19分01秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
const int mod = 1e9+7;
long long dp[2010], a[2010];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	//k   2k - 1 2k 2k + 1
	//1   1      2  3
	//2   3      4  5
	//3   5      6  7
	//4   7      8  9
	int n;
	cin >> n;
	long long ans = 0;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for(int i = 2; i < n; ++i) {
		int k = a[i - 1] < a[i];
		for(int j = i - 2; j >= 0; --j) {
			if(a[j] < a[i]) {
				k++;
			}else if(a[j] > a[i]){
				dp[i] = (dp[i] + (dp[j] + 1) * k) % mod;
			}
		}
		ans = (dp[i] + ans) % mod;
	}
	cout << ans << endl;
    return 0;
}
