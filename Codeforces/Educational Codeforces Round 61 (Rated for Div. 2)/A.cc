/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月05日 星期二 23时04分10秒
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
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	long long L = 0, R = 0;
	if(a == 0 && d == 0 && c > 0)  return cout << 0 << endl,0;
	L += a * 2 + b + c;
	R += d * 2 + b + c;
	cout << ((L == R) ? 1 : 0) << endl;
    return 0;
}
