/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月07日 星期四 23时06分26秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    //ios::sync_with_stdio(false); cin.tie(0);
	string s,b;
	cin >> s >> b;
	int a1 = (s[0] - '0') * 10 + s[1] - '0', b1 = (s[3] - '0') * 10 + s[4] - '0';
	a1 *= 60;
	int a2 = (b[0] - '0') * 10 + b[1] - '0', b2 = (b[3] - '0') * 10 + b[4] - '0';
	a2 *= 60;
	int t = ((a2 + b2) - (a1 + b1)) / 2;
	int p = (a1 + t + b1) / 60;
	int q = (a1 + t + b1) % 60;
	printf("%02d:%02d\n",p,q);
    return 0;
}
