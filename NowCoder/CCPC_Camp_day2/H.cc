/*************************************************************************
    > File Name: H.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年10月02日 星期二 12时11分01秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
   // freopen("input.in","r",stdin);
#endif
	int T,n,m,k;
	cin>>T;
	while(T--){
		cin>>n>>m>>k;
		double  ans = 0;
		for(int i = 1; i <= k; ++i){
			ans += 1.0 * (n-i+1)/(m-i+1);
		}
		printf("%f\n",ans);
	}
    return 0;
}
