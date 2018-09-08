#include<bits/stdc++.h>
const int N = 1e5+10;
int loc[N][101],up[101],n,m,k,x,y,T,w;

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&k);
		memset(loc,0,sizeof loc);
		memset(up,0,sizeof up);
		for(int i = 0; i < k; ++i){
			scanf("%d%d",&x,&y);
			loc[x][y] = 1;
		}
		long long ans = 0;
		for(int i = 1; i <= n; ++i){
			for(int j = 1; j <= m; ++j){
				if(loc[i][j]) //第j列中为黑块的行(在1~i行中取最大行标)
					up[j] = i;
			}
			for(int j = 1; j <= m; ++j){ //以(i,j)为右下角的矩阵的子矩阵个数
				int minH = 1<<30; //统计矩阵长为K时高最大为多少
				for(int K = j; K >= 1; --K){ //枚举矩阵长度
					//K代表以(i,j)为右下角，长为K的矩阵左边界下标
					minH = std::min(minH,i-up[K]); //i-up[K]代表此列能取得的最大高
					ans += minH;
				}
			}
		}
		printf("Case #%d: %lld\n",++w,ans);
	}
	return 0;
}
