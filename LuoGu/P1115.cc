/*************************************************************************
    > File Name: P1115.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年11月10日 星期六 17时30分56秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
int a[200100];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n;
	cin>>n;
	for(int i = 1; i <= n; ++i) {
		cin>>a[i];
	}
	int sum = a[1], thisSum = 0;
	for(int i = 1; i <= n; ++i) {
		thisSum += a[i];
		if(thisSum > sum) 
			sum = thisSum;
		else if(thisSum < 0)
			thisSum = 0;
	}
	cout<< sum <<endl;
    return 0;
}
