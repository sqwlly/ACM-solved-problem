/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年11月22日 星期四 23时33分28秒
 ************************************************************************/

#include<bits/stdc++.h>
typedef long long LL;
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	LL n,s, ans = 0;
	cin>>n>>s;
	ans = s / n;
	if(s % n == 0) {
		cout<< ans <<endl;
	}else {
		cout<< ans + 1 << endl;
	}
    return 0;
}
