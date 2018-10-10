/*************************************************************************
    > File Name: D.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年10月04日 星期四 12时35分12秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
int a[100010];
int main()
{
#ifndef ONLINE_JUDGE
#endif
	int n;
	cin>>n;
	for(int i = 0; i < n; ++i)
		cin>>a[i];
	sort(a,a+n);
	long long sum = 0;
	for(int i = 1; i < n; ++i){
		sum += a[i] + a[0];
	}
	cout<<sum<<endl;
    return 0;
}
