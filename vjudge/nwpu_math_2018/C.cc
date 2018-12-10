/*************************************************************************
    > File Name: C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年12月10日 星期一 09时25分32秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
const int N = 500100;
int a[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	for(int i = 1; i < N; ++i) {
		for(int j = i + i; j < N; j += i) {
			a[j] += i;
		}
	}

	int T,n;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		printf("%d\n",a[n]);
	}
    return 0;
}
