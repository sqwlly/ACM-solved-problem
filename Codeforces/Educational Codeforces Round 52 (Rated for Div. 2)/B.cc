/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年10月11日 星期四 23时05分04秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;

int  main()
{
#ifndef ONLINE_JUDGE
   // freopen("input.in","r",stdin);
#endif
	long long n,m;
	cin>>n>>m;
	if(m == 0){
		cout<<n<<' '<<n<<endl;
		return 0;
	}
	long long sum = 0;
	for(long long i = 1; i < n; ++i){
		sum += i;
		if(sum >= m){
			sum = i + 1;
			break ;
		}
	}
	long long min1 = n - 2 * m;
	if(min1 < 0)
		min1 = 0;
	long long max1 = n - sum;
	max1 = max(0LL,max1);
	cout<<min1<<' '<<max1<<endl;
    return 0;
}
