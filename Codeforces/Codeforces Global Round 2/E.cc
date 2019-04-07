/*************************************************************************
    > File Name: E.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年04月07日 星期日 17时44分04秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
typedef long long LL;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	LL n, ans = 0, res = 0, x;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> x;
		int t = min(res, x / 2); //每次选两个与之前剩下的组成(x,x,y)
		res -= t;
		x -= 2 * t;
		ans += t + x / 3; //同时自己可以组成(x,x,x)
		res += x % 3; //剩余的
	}
	cout << ans << endl;
    return 0;
}
