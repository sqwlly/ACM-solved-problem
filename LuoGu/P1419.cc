/*************************************************************************
    > File Name: P1419.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年09月29日 星期六 16时33分27秒
 ************************************************************************/

#include<bits/stdc++.h>
typedef long long LL;
using namespace std;

LL n,x,S,T,sum[100010],a[100010];

bool love(LL x)
{
	memset(sum,0,sizeof sum);
	for(int i = 1; i <= n; ++i)
		sum[i] = sum[i - 1] + a[i] - x;
	deque<LL> dq;
	for(int i = 1, s = S; s <= n; ++i, ++s){
		while(!dq.empty() && sum[dq.back()] > sum[i - 1])
			dq.pop_back();
		while(!dq.empty() && dq.front() + T < s) 
			dq.pop_front();
		dq.push_back(i - 1);
		if(sum[s] - sum[dq.front()] >= 0) return 1;
	}
	return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	cin>>n>>S>>T;
	for(int i = 1; i <= n; ++i){
		cin>>a[i];
		a[i] *= 10000;
	}
	int L = -1e9, R = 1e9;
	while(L + 1 < R){
		LL mid = (L + R)>>1;
		if(love(mid))
			L = mid;
		else 
			R = mid;
	}
	printf("%.3f\n",1.0*L/10000);
    return 0;
}
