/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年10月27日 星期六 09时02分25秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n,m;
	cin>>n>>m;
	int cnt = n/2;
	if(n & 1) cnt++;
	for(int t = cnt; t <= n; ++t){
		if(t % m == 0){
			printf("%d\n",t);
			return 0;
		}
	}
	puts("-1");
    return 0;
}
