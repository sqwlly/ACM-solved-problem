/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年10月03日 星期三 12时03分51秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;

struct node{
	int cost,flag;
	bool operator < (const node & u)const{
		return cost < u.cost;
	}
}a[1010];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int T,n,m;
	cin>>T;
	while(T--){
		cin>>n>>m;
		int cnt = 0;
		for(int i = 0; i < n; ++i){
			cin>>a[i].cost>>a[i].flag;	
			if(a[i].flag) cnt++;
		}
		sort(a,a+n);
		double sum = 0;
		for(int i = n - 1; i >= 0; --i){
			if(cnt && m) {
				sum += a[i].cost * 1.0 / 2;
				cnt--;
				m--;
			}else{
				sum += a[i].cost;
			}
		}
		printf("%.1f\n",sum);
	}
    return 0;
}
