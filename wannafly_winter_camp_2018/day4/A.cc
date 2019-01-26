/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年01月23日 星期三 15时48分38秒
 ************************************************************************/

#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
const int N = 100100;

struct node{
	int x,y;
}a[N],b[N];

int dis(node u,node v)
{
	return abs(u.x - v.x) + abs(u.y - v.y);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n,m;
	cin >> n >> m;
	long long ans = 0;
	for(int i = 1; i <= n; ++i) {
		scanf("%d %d %d %d",&a[i].x,&a[i].y,&b[i].x,&b[i].y);
		if(i == 1) continue;
		ans += min(dis(a[i - 1], a[i]) + dis(b[i - 1], b[i]), dis(a[i - 1], b[i]) + dis(b[i - 1], a[i]));
	}
	cout << ans + dis(a[n],b[n]) << endl;
	return 0;
}
