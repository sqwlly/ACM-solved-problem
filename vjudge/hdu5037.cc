/*************************************************************************
    > File Name: hdu5037.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年10月14日 星期日 16时56分38秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;

int n,m,L,a[200100];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	ios::sync_with_stdio(false);
	int T, w = 0;
	cin>>T;
	while(T--){
		cin>>n>>m>>L;
		for(int i = 1; i <= n; ++i){
			cin>>a[i];
		}
		a[n + 1] = m;
		sort(a + 1,a + n + 1);
		int cnt = 0, pre = -L;
		for(int i = 1; i <= n + 1; ++i){
			cnt += (a[i] - a[i-1]) / (L + 1) * 2;
			pre += (a[i] - a[i-1]) / (L + 1) * (L + 1);
			if(a[i] - pre > L){ //剩余的大于L就需要单独再跳一次，否则就可以归为上一步
				pre = a[i-1] + (a[i] - a[i-1]) / (L + 1) * (L + 1);
				cnt++;
			}
		}
		printf("Case #%d: %d\n",++w,cnt);
	}
    return 0;
}
