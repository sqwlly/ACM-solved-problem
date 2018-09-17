/*************************************************************************
    > File Name: P1563.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年09月17日 星期一 20时10分49秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;

struct person{
	bool dir;
	char s[12];
}a[100010];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("P1563.in","r",stdin);
#endif
	int n,m,d,x; char s[10];
	scanf("%d%d",&n,&m);
	for(int i = 0; i < n; ++i){
		scanf("%d %s",&d,s);
		a[i].dir = d;
		strcpy(a[i].s,s);
	}
	int dx = 0;
	for(int i = 0; i < m; ++i){
		scanf("%d%d",&d,&x);
		d = d ^ a[dx].dir;
		dx = (dx + (d?1:-1) * x + n) % n;	
	}
	printf("%s\n",a[dx].s);
    return 0;
}
