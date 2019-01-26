/*************************************************************************
    > File Name: C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年01月26日 星期六 09时03分09秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
const int N = 3E5+10;
int cnt[N], u[N],v[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n,m;
	cin >> n >> m;
	for(int i = 0; i < m; ++i) {
		scanf("%d %d",&u[i],&v[i]);
		cnt[u[i]]++;
		cnt[v[i]]++;
	}
	for(int i = 0; i < m; ++i) {
		if(cnt[u[i]] > 1 && cnt[v[i]] > 1) {
			return puts("No"),0;
		}
	}
	puts("Yes");
    return 0;
}
