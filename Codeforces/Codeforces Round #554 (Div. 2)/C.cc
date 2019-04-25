/*************************************************************************
    > File Name: C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年04月25日 星期四 07时34分35秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
typedef long long LL;
using namespace std;
vector<LL> v;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	LL a,b, ans = 0;
	cin >> a >> b;
	if(a < b) swap(a,b);
	LL dif = a - b, min1 = LLONG_MAX >> 1;
	for(LL i = 1; i * i <= dif; ++i) {
		if(dif % i == 0) v.emplace_back(i),v.emplace_back(dif / i);
	}
	for(auto d : v) {
		LL k = 1LL * ceil(1.0 * a / d) * d - a;
		LL lcm = (a + k) * (b + k) / d;
		if(lcm < min1) {
			min1 = lcm;
			ans = k;
		}
	}
	cout << ans << endl;
    return 0;
}
