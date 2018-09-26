/*************************************************************************
    > File Name: P1883.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年09月26日 星期三 09时20分17秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;

struct node{
	int a,b,c;
}dx[100010];
int n,T;
double maxV(double x)
{
	double max1 = -1e9;
	for(int i = 0; i < n; ++i){
		double v = dx[i].a * x * x + dx[i].b * x + dx[i].c;
		max1 = max(v,max1);
	}
	return max1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	cin>>T;
	while(T--){
		cin>>n;
		for(int i = 0; i < n; ++i){
			cin>>dx[i].a>>dx[i].b>>dx[i].c;
		}
		double l = 0, r = 1010;
		while(l + (1e-7) < r){
			double mid = l + (r - l) / 3;
			double mid_r = r - (r - l) / 3;
			if(maxV(mid) < maxV(mid_r))
				r = mid_r;
			else
				l = mid;
		}
		printf("%.4f\n",maxV(l));
	}
    return 0;
}
