/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年10月29日 星期一 00时08分16秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
int a[1010],x[1010];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n;
	cin>>n;
	x[0] = 1e9;
	for(int i = 1; i <= n; ++i){
		cin>>a[i];
		x[i] = 1e9;
	}
	vector<int> v;
	for(int k = 1, f = 0; k <= n; ++k, f = 0){
		for(int i = 0; i <= n; ++i)
			x[i] = 1e9;
		for(int i = n; i >= 1; --i){
			int t = (i-1)%k;
			int tmp = a[i] - a[i - 1];
			if(x[t]==1e9)
			x[(i-1)%k] = a[i] - a[i-1];
			else if(x[t] != tmp) {
				f = 1; break;
			}
		}
		if(!f) v.push_back(k);
	}
	printf("%d\n",(int)v.size());
	for(int i = 0; i < v.size(); ++i)
		printf("%d%c",v[i],i==v.size()-1?'\n':' ');
    return 0;
}
