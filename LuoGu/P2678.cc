/*************************************************************************
    > File Name: P2678.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年09月25日 星期二 21时25分00秒
 ************************************************************************/

#include<bits/stdc++.h>
typedef long long LL;
using namespace std;

int L,N,M,a[100010],vis;

bool ok(int x)
{
	int ret = 0, sx = 0;
	for(int i = 1 ; i <= N+1; ++i){
			if(a[i] - a[sx] < x)
				ret++;
			else 
				sx = i;
	}
	return ret <= M;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	cin>>L>>N>>M;
	for(int i = 1; i <= N; ++i)
		cin>>a[i];
	a[N+1] = L;
	int j = L, i = 1;
	while(i <= j){
		int mid = (i+j)/2;
		if(ok(mid))
			i = mid+1;
		else
			j = mid-1;
	}
	cout<<i-1<<endl;
    return 0;
}
