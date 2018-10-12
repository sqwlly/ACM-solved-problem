/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年10月11日 星期四 22时47分42秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int t;
	cin>>t;
	while(t--){
		int s,a,b,c;
		cin>>s>>a>>b>>c;
		long long cnt = s / c;
		long long ret = cnt / a * b;
		cout<<cnt + ret<<endl;
	}
    return 0;
}
