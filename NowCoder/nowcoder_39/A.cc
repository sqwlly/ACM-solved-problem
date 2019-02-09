/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年02月08日 星期五 19时02分57秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	long long n,sx,sy,ex,ey;
	cin >> n >> sx >> sy >> ex >> ey;
	long long ans = max(abs(sx-ex),abs(sy-ey));
	cout << ans << endl;
    return 0;
}
