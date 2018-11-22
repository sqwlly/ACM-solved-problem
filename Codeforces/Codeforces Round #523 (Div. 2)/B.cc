/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年11月23日 星期五 00时02分30秒
 ************************************************************************/

#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
int a[100100];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n,m,x,max1 = 0,cnt = 0;
	LL sum = 0;
	cin>>n>>m;
	for(int i = 0; i < n; ++i) {
		scanf("%d",&x);
		max1 = max(max1,x);
		sum += x - 1;
		a[i] = x;
	}
	sort(a,a+n);
	int last = 0;
	for(int i = 0; i < n; ++i) {
		if(i == n - 1 && a[i] > last) {
			last = a[i] - last;
			sum = sum - last + 1;
			break;
		}else if(i == n -1){
			break;
		}
		if(a[i] > last) last++;
	}
	cout<<sum<<endl;
    return 0;
}
