/*************************************************************************
    > File Name: poj1185.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年10月24日 星期三 17时01分59秒
 ************************************************************************/

#include<cstdio>
#include<cstring>
#define max(a,b) ((a) > (b) ? (a) : (b))
using namespace std;

int n,m;
char map[110][20], num[110], top;
int state[70], cur[70], dp[110][70][70];

bool ok(int x) {
	if((x & (x << 1)) || (x & (x << 2))) return 0;
	return 1;
}

int getNum(int x) {
	int cnt = 0;
	while(x) {
		cnt++;
		x &= (x - 1);
	}
	return cnt;
}

void init()
{
	top = 0;
	for(int i = 0; i < (1 << m); ++i) 
		if(ok(i))  state[++top] = i;
	memset(dp,-1,sizeof dp);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	init();
	for(int i = 1; i <= n; ++i)
		scanf("%s",map[i] + 1);
	for(int i = 1; i <= n; ++i) {
		cur[i] = 0;
		for(int j = 1; j <= m; ++j){
			if(map[i][j] == 'H') cur[i] |= (1 << (j - 1));
		}
	}
	for(int j = 1; j <= top; ++j) {
		num[j] = getNum(state[j]);
		if((state[j] & cur[1]) == 0) 
			dp[1][j][1] = num[j];
	}
	for(int i = 2; i <= n; ++i) { //第i行
		for(int j = 1; j <= top; ++j) { //第i行布局为j
			if(state[j] & cur[i]) continue;
			for(int k = 1; k <= top; ++k) { //第i-1行布局为k
				if(state[j] & state[k]) continue;
				for(int m = 1; m <= top; ++m) {
					if(state[j] & state[m]) continue; // j与m相容
					if(state[k] & state[m]) continue; // k与m相容
					if(dp[i - 1][k][m] == -1) continue; 
					dp[i][j][k] = max(dp[i][j][k], dp[i - 1][k][m] + num[j]);
				}
			}
		}
	}
	int ans = 0;
	for(int i = 1; i <= top; ++i)
		for(int j = 1; j <= top; ++j) ans = max(ans, dp[n][i][j]);
	printf("%d\n",ans);
    return 0;
}
