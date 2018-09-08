#include<bits/stdc++.h>
typedef long long LL;
int a[21],b[21],state[1<<21],n,p,d;
LL dp[1<<21];
void pupil(int cur,int t,LL v)
{
	if(dp[cur] < v || dp[cur] == -1)
		dp[cur] = v;
	else
		return;
	for(int i = 0; i < n; ++i){
		int love = cur & (1<<i);
		if(love||(cur & state[i]) != state[i]) continue;
		pupil(cur|(1<<i),t+1,v+1LL*t*a[i]+1LL*b[i]);
	}
}

int main()
{
	scanf("%d",&n);
	for(int i = 0; i < n; ++i){
		scanf("%d%d%d",a+i,b+i,&p);
		for(int j = 0; j < p; ++j){
			scanf("%d",&d);
			d--;
			state[i] += (1<<d);
		}
	}
	memset(dp,-1,sizeof dp);
	pupil(0,1,0);
	LL shit = 0;
	for(int i = 0; i < (1<<n); ++i)
		shit = std::max(shit,dp[i]);
	printf("%lld\n",shit);
	return 0;
}
