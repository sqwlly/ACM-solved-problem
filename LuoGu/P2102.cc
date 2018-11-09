/*************************************************************************
    > File Name: P2102.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年11月09日 星期五 14时41分05秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
int s[101][101];

int you(int x,int y)
{
	int cur = 0;
	if(s[x - 1][y]) cur |= (1<<s[x - 1][y]);
	if(s[x][y - 1]) cur |= (1<<s[x][y - 1]);
	if(s[x][y + 1]) cur |= (1<<s[x][y + 1]);
	for(int i = 1; ; ++i) if(!(cur & (1 << i))) return i;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n,m;
	cin>>n>>m;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			if(s[i][j]) continue;
			int love = you(i,j), x = i + 1, y = j + 1;
			while("you") {
				if(s[i][y] || s[x][j] || x > n || y > m) break;
				int shit = you(i,y);
				if(shit != love) break;
				x++,y++; //不断扩展正方形
			}
			for(int a = i; a < x; ++a) {
				for(int b = j; b < y; ++b) {
					s[a][b] = love;
				}
			}
		}
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			putchar(s[i][j] +  'A' - 1);
		}
		puts("");
	}
    return 0;
}
