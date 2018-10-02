/*************************************************************************
    > File Name: P2440.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年09月29日 星期六 16时53分13秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;

int n,k,a[100010];

bool love(int mid)
{
	int ret = 0;
	for(int i = 0; i < n; ++i)
		ret += a[i]/mid;
	return ret >= k;
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	cin>>n>>k;
	for(int i = 0; i < n; ++i){
		cin>>a[i];
	}
	int l = 1, r = *max_element(a,a+n);
	while(l < r){
		int mid = l + (r - l)/2;
		if(love(mid)) l = mid + 1;
		else r = mid - 1;
	}
	l--;
	if(l < 1) l = 0;
	cout<<l<<endl;
    return 0;
}
