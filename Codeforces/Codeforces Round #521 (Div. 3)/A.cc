/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年11月16日 星期五 22时38分17秒
 ************************************************************************/

#include<bits/stdc++.h>
typedef long long LL;
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int t;
	cin>>t;
	while(t--) {
		LL a,b,k,ans = 0,x=0;
		cin>>a>>b>>k;
		if(k & 1) {
			ans = x + (k/2+1) *a - k/2*b;
		}else{
			ans = x + (k/2)*a - k / 2 * b;
		}
		cout<<ans<<endl;
	}

    return 0;
}
