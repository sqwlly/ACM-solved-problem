/*************************************************************************
    > File Name: C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年02月13日 星期三 13时40分02秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	long long l = 1032, r = 12302135942453, d = 234;
	int b = ceil(1.0 * 1032 / d) * d;
	long long cnt = (r - b) / d + 1;
	cout << cnt << endl;
    return 0;
}
