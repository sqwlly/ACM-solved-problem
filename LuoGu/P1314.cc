/*************************************************************************
    > File Name: P1314.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年10月09日 星期二 20时00分00秒
 ************************************************************************/

#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
const int N = 2e5+10;
LL n,m,S,ans = 1e18,ret,w[N],v[N],L[N],R[N],sum_i[N],sum_w[N];

int love(int W)
{
	memset(sum_i,0,sizeof sum_i);
	memset(sum_w,0,sizeof sum_w);
	for(int i = 1; i <= n; ++i){
		if(w[i] >= W){
			sum_i[i] = sum_i[i - 1] + 1;
			sum_w[i] = sum_w[i - 1] + v[i];
		}else{
			sum_i[i] = sum_i[i - 1];
			sum_w[i] = sum_w[i - 1];
		}
	}
	LL Y = 0;
	for(int i = 1; i <= m; ++i){
		Y += (sum_i[R[i]] - sum_i[L[i] - 1]) * (sum_w[R[i]] - sum_w[L[i] - 1]);
	}
	LL t = S - Y;
	ret = t > 0 ? t : -t;
	ans = min(ret,ans);
	return Y - S > 0;
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	cin>>n>>m>>S;
	for(int i = 1; i <= n; ++i){
		cin>>w[i]>>v[i];
	}
	for(int i = 1; i <= m; ++i){
		cin>>L[i]>>R[i];
	}
	LL l = -1, r = 1e13;
	//LL l = min_element(w+1,w+n+1) - w, r = max_element(w+1,w+n+1) - w;
	while(l <= r){
		LL mid = l + (r - l)/2;
		if(love(mid)) l = mid + 1;
		else r = mid - 1;
	}
	cout<<ans<<endl;
    return 0;
}
