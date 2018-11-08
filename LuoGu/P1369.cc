/*************************************************************************
    > File Name: P1369.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年11月08日 星期四 13时19分47秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
int G[303][303];

int love(int a,int b,int c,int d) //(a,b)为左上角，(c,d)为右下角
{
	if(a > c || b > d) return 0;
	return G[c][d] - G[c][b - 1] - G[a - 1][d] + G[a - 1][b - 1];
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n,x,y, max_x = 0, max_y = 0;
	scanf("%d",&n);
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			scanf("%d%d",&x,&y);
			G[x][y] = 1;
			max_x = max(x,max_x); 
			max_y = max(y,max_y);
		}
	}
	for(int i = 1; i <= max_x; ++i) {
		for(int j = 1; j <= max_y; ++j) {
			G[i][j] = G[i - 1][j] + G[i][j - 1] - G[i - 1][j - 1] + G[i][j];
		}
	}
	int ans = 0;
	for(int i = 1; i <= max_x; ++i) {
		for(int j = 1; j <= max_y; ++j) {
			for(int a = 2; a <= max_x; ++a) {
				for(int b = 2; b <= max_y; ++b) {
					if(i > a || j > b) continue;
					int t = love(i,j,a,b) - love(i + 1,j + 1,a - 1, b - 1);
					ans = max(t, ans);
				}
			}
		}
	}
	printf("%d\n",ans);
    return 0;
}
