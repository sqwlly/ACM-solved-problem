/*************************************************************************
    > File Name: P1083.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年10月11日 星期四 09时31分35秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
const int N = 1e6+10;
int n,m,num[N];

struct node{
	int v,l,r;
}a[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	cin>>n>>m;
	for(int i = 0; i < n; ++i){
		cin>>num[i];
	}
	for(int i = 0; i < m; ++i){
		cin>>a[i].v>>a[i].l>>a[i].r;
	}
	for(int i = 0; i < m; ++i){
		
	}
    return 0;
}
