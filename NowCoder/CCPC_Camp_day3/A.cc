/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年10月03日 星期三 13时24分33秒
 ************************************************************************/

#include<bits/stdc++.h>
typedef long long LL;
using namespace std;

LL solve(LL x,LL y)
{
	if(x == 1 && y == 0)
		return 3;
	if(x == 2 && y == 2)
		return 4;
	if(y > x - y)
		return x - y - 2 * floor(double(x - y - y) / 3.0);
	else
		return x - y - 2 * floor(double(x - y - y) / 4.0);
}

int main()
{
#ifndef ONLINE_JUDGE
#endif
	int T,n,m;
	cin>>T;
	while(T--){
		cin>>n>>m;
		n = fabs(n), m = fabs(m);
		if(n < m)
			swap(n,m);
		cout<<solve(n,m)<<endl;
	}
    return 0;
}
