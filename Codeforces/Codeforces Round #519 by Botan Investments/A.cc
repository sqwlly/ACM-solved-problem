/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年10月28日 星期日 23时31分48秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n,a[200] = {0};
	cin>>n;
	int ret = 0, sum = 0;
	for(int i = 0; i < n; ++i){
		cin>>a[i];
		ret += a[i];
	}
	sort(a,a+n);
	for(int k = a[n-1]; k ; ++k)

	for(int i = 0, sum = 0; i < n; ++i){ 
		sum += k - a[i];
	//	cout<<sum<<endl;
		if(sum > ret) return cout<<(k)<<endl,0;
	}
    return 0;
}
