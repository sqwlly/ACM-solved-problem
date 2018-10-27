/*************************************************************************
    > File Name: C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年10月27日 星期六 09时54分17秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
   // freopen("input.in","r",stdin);
#endif
	int a,b, sum = 0;
	cin>>a>>b;
	for(int i = 3; i <= 10000; ++i){
		if(i%b==0)
			continue;
		int k = (i/b)/(i%b);
		if(k >= 1 && k <= a){
			sum += i;
			cout<<i<<' ';
		}
	}
	puts("");
	cout<<sum<<endl;
    return 0;
}
