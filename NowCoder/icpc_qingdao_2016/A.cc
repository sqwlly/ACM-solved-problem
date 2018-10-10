/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年10月07日 星期日 12时03分30秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
#endif
	int T,n;
	cin>>T;
	while(T--){
		cin>>n;
		int sum = 0,a,b;
		for(int i = 0; i < n; ++i){
			cin>>a>>b;
			sum += a * b;
		}
		cout<<sum<<endl;
	}

    return 0;
}
