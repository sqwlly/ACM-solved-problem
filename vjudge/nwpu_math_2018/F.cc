/*************************************************************************
    > File Name: F.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年12月06日 星期四 00时17分25秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
typedef long long LL;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int T, t = 1;
	cin >> T;
	while(T--) {
		LL n;
		cin >> n;
		cout << "Case " << t++ << ": " << n - (LL)sqrt(n) - (LL)sqrt(n / 2.0) << endl;
	}
    return 0;
}
