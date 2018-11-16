/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年11月16日 星期五 22时48分30秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
int a[111];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n;
	cin>>n;
	for(int i = 0; i < n; ++i) {
		cin>>a[i];
	}
	int cnt = 0;
	for(int i = 1; i < n; ) {
		if(a[i - 1] == 1 && a[i + 1] == 1 && a[i] == 0) {
			cnt++;
			i += 3;
		}else{
			i++;
		}
	}
	cout<<cnt<<endl;
    return 0;
}
