/*************************************************************************
    > File Name: D.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年10月27日 星期六 10时29分22秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;

int a[10010][4];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int num = 1;
	for(int i = 0; i < 10010; ++i){
		a[i][0] = num++;
		a[i][1] = num++;
		a[i][2] = num++;
		a[i][3] = ++num;
		num+=2;
	}
	int n,k;
	cin>>n>>k;
	int m = a[n-1][3] * k;
	printf("%d\n",m);
	for(int i = 0; i < n; ++i){
		printf("%d %d %d %d\n",a[i][0] * k,a[i][1] * k, a[i][2] * k, a[i][3] * k);
	}
    return 0;
}
