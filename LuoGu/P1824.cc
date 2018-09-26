/*************************************************************************
    > File Name: P1824.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年09月26日 星期三 15时39分54秒
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int a[100010],n,c;
bool ok(int d)
{
	int now = a[0] ,ret = 1;
	for(int i = 1; i < n; ++i){
		if(a[i] - now >= d){
			ret++;
			now = a[i];
		}
		if(ret == c) break;
	}
	return ret >= c;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	cin>>n>>c;
	for(int i = 0; i < n; ++i){
		cin>>a[i];
	}
	sort(a,a+n);
	int r = 1e9+10, l = 1;
	while(l <= r){
		int mid = l + (r - l) / 2;
		if(ok(mid))
			l = mid + 1;
		else
			r = mid - 1;
	}
	if(ok(r)) l = r;
	cout<<l<<endl;
    return 0;
}
