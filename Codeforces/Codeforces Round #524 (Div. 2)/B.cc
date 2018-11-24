/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年11月24日 星期六 15时44分43秒
 ************************************************************************/

#include<bits/stdc++.h>
typedef long long LL;
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int q,l,r; 
	cin>>q;
	while(q--) {
		scanf("%d%d",&l,&r);
		LL sum = 0;
		if(l & 1) {
			if(r & 1) { 
				// 1 4 // 1 3
				int n = (r - l + 1) / 2 + 1;
				sum -= n * 1LL * l + 1LL *n * (n - 1);
				n--;
				sum += n * 1LL * (l + 1) + 1LL * n * (n - 1);
			}else{
				int n = (r - l + 1) / 2;
				sum -= n * 1LL * l + 1LL * n * (n - 1); // 2 * 1 + 2 
				sum += n * 1LL * (l + 1) + 1LL * n * (n - 1);//2 * 2 + 2 
			}
		}else{
			if(r & 1) { 
				int n = (r - l + 1) / 2; // 2 * 2 + 2
				sum += n * 1LL * l + 1LL *n * (n - 1);
				sum -= n * 1LL * (l + 1) + 1LL * n * (n - 1);
			}else{
				int n = (r - l + 1) / 2 + 1;
				sum += n * 1LL * l + 1LL * n * (n - 1);
				n--;
				sum -= n * 1LL * (l + 1) + 1LL * n * (n - 1);
			}
		}
		printf("%lld\n",sum);
	}
    return 0;
}
