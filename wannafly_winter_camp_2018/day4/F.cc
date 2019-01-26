/*************************************************************************
    > File Name: F.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年01月26日 星期六 09时18分31秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;

bool isWhite(int x,int y)
{
	return (x & 1) == (y & 1);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n,m,sx,sy,ex,ey;
	cin >> n >> m >> sx >> sy >> ex >> ey;
	if(isWhite(sx,sy) != isWhite(ex,ey)) {
		puts("Yes");
	}else{
		puts("No");
	}
    return 0;
}
