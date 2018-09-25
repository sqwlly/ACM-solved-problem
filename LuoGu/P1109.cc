/*************************************************************************
    > File Name: P1109.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年09月25日 星期二 18时11分36秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;

int n,L,R,a[52];

int solve()
{
	int ret = 0, ter = 0;
	for(int i = n-1 ; i >= 0; --i){
		if(a[i] > R)
			ret += a[i] - R;
		else if(a[i] < L)
			ter += L - a[i];
	}
	if(ter > ret)
		ret += ter - ret;
	printf("%d\n",ret);
}

int main()
{
#ifndef ONLINE_JUDGE
   // freopen("input.in","r",stdin);
#endif
	cin>>n;
	int sum = 0;
	for(int i = 0; i < n; ++i)
		cin>>a[i];
	for(int i = 0; i < n; ++i)
		sum += a[i];
	cin>>L>>R;
	double ret = 1.0*sum/n;
	if(ret < L || ret > R){
		puts("-1");
		return 0;
	}
	sort(a,a+n);
	solve();
    return 0;
}
