/*************************************************************************
    > File Name: C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年10月07日 星期日 12时52分54秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int T;
	cin>>T;
	while(T--){
		double l, d;
		cin>>l>>d;
		if(l <= d)
			printf("%.6f\n",0);
		else
			printf("%.6f\n",log(l/d) + 1);
	}
    return 0;
}
