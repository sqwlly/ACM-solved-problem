/*************************************************************************
    > File Name: F.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com
    > Created Time: 2019年01月26日 星期六 09时18分31秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;

int dir[8][2] = {-2,-1, -2,1, -1,-2, -1,2, 1,-2, 1,2, 2,-1, 2,1};
bool vis[11][11];
int n,m,sx,sy,ex,ey,rec;

bool isWhite(int x,int y)
{
	return (x & 1) == (y & 1);
}

void dfs(int x,int y,int white,int black)
{
	if(x == ex && y == ey) {
		if(white == black) {
			rec = 1;
			return;
		}
	}
	for(int i = 0; i < 8; ++i) {
		int tx = x + dir[i][0];
		int ty = y + dir[i][1];
		if(tx < 1 || tx > n || ty > m || ty < 1 || vis[tx][ty])
			continue;
		vis[tx][ty] = 1;
		if(isWhite(tx,ty)) white++;
		else black++;
		dfs(tx,ty,white,black);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.in", "r", stdin);
#endif
	cin >> n >> m >> sx >> sy >> ex >> ey;
	if (n >= 3 && m >= 3) {
		if ((sx == 2 && sy == 2) || (ex == 2 && sy == 2)) {
			puts("No");
			return 0;
		}
		if (isWhite(sx, sy) == isWhite(ex, ey))
			puts("No");
		else
			puts("Yes");
	} else {
		if(n == 2) {
			int k1 = abs(sy - ey);
			if(abs(sx - ex) == 1 && k1 % 2 == 0 && k1 % 4 != 0) {
				puts("Yes");
			}else{
				puts("No");
			}
			return 0;
		}else if(m == 2){
			int k1 = abs(sx - ex);
			if(abs(sy - ey) == 1 && k1 % 2 == 0 && k1 % 4 != 0) {
				puts("Yes");
			}else{
				puts("No");
			}
			return 0;
		}
		int white = 0, black = 0;
		if (isWhite(sx, sy)) white++;
		else black++;
		dfs(sx, sy, white, black);
		puts(rec ? "Yes" : "No");

	}
	return 0;
}

