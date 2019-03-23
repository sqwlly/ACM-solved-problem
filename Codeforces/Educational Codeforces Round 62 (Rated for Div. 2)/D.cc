/*************************************************************************
    > File Name: D.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月23日 星期六 00时09分03秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	long long n, ans = 0;
	cin >> n;
	for(int i = 2; i < n; ++i) {
		ans += i * (i + 1);
	}
	cout << ans << endl;
    return 0;
}
