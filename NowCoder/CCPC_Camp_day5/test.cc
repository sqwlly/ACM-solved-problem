/*************************************************************************
    > File Name: test.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年10月05日 星期五 21时10分26秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;

int fac(int n)
{
	int ret = 1;
	for(int i = 1; i <= n; ++i)
		ret *= i;
	return ret;
}
int main()
{
#ifndef ONLINE_JUDGE
#endif
	int n;
	cin>>n;
	double e = 1;
	for(int i = 1; i < 12; ++i){
		e += 1.0/fac(i);
	}
	printf("%.16f\n",e);
    return 0;
}
