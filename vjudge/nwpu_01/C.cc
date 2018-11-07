/*************************************************************************
    > File Name: C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年10月27日 星期六 09时54分17秒
 ************************************************************************/

#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
const int mod = 1e9+7;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	LL a,b;
	cin>>a>>b;
	LL t = ((b + 1) * a ) % mod;
	LL tmp = (a * (a - 1) / 2) % mod;
	tmp = tmp * b % mod;
	tmp = (tmp + t) % mod;
	t = (b - 1) * b / 2 % mod;
	cout<<(t * tmp) % mod<<endl;
    return 0;
}
