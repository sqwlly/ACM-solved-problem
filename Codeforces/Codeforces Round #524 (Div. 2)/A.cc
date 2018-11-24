/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年11月24日 星期六 15时34分14秒
 ************************************************************************/

#include<bits/stdc++.h>
typedef long long LL;
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n,k;
	cin>>n>>k;
	int one[3] = {2,5,8};
	for(int i = 0; i < 3; ++i) {
		one[i] = ceil(n * one[i] * 1.0 / k);
	}
	LL sum = 0;
	for(int i = 0; i < 3; ++i)
		sum += one[i];
	cout << sum << endl;
    return 0;
}
