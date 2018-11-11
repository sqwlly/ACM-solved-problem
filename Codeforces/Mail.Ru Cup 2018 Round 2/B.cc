/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年11月12日 星期一 01时03分47秒
 ************************************************************************/

#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
const int N = 100100;
bool vis[N];
int a[N];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n,m,l,cnt = 0;
	scanf("%d%d%d",&n,&m,&l);
	for(int i = 1; i <= n; ++i) {
		scanf("%d",a + i);
		if(a[i] > l) {
			vis[i] = 1;
			if(!vis[i - 1]) cnt++;
		}
	}
	int op = 0, p, d;
	for(int i = 0; i < m; ++i) {
		scanf("%d",&op);
		if(!op) printf("%d\n", cnt);
		else{
			scanf("%d%d",&p, &d);
			a[p] += d;
			if(!vis[p] && a[p] > l) {
				vis[p] = 1;
				if(vis[p - 1] && vis[p + 1]) 
					cnt--;
				else if(!vis[p - 1] && !vis[p + 1])
					cnt++;
			}
		}
	}
    return 0;
}
