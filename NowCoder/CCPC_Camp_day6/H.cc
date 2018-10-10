/*************************************************************************
    > File Name: H.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年10月06日 星期六 12时10分37秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
int a[1010];

int main()
{
#ifndef ONLINE_JUDGE

#endif
	int n;
	cin>>n;
	for(int i = 0; i < n; ++i)
		cin>>a[i];
	int ans = *max_element(a,a+n);
	cout<<ans*2<<endl;
    return 0;
}
