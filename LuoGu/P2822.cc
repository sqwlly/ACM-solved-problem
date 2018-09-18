#include<bits/stdc++.h>
typedef long long LL;
using namespace std;

//组合数打表模板,适用于N<=3000
//c[i][j]表示从i个中选j个的选法。
int C[2018][2018], sum[2018][2018];

void get_C(int maxn,int k)
{
    C[0][0] = 1;
    for(register int i=1;i<=maxn;i++)
    {
        C[i][0] = 1;
        for(register int j=1;j<=i;j++)
            C[i][j] = (C[i-1][j]%k+C[i-1][j-1]%k)%k;
        //C[i][j] = (C[i-1][j]+C[i-1][j-1])%MOD;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n,m,t,k;
	scanf("%d%d",&t,&k);
	get_C(2017,k);
	for(int i = 1; i < 2018; ++i){
		for(int j = 1; j < 2018; ++j){
			sum[i][j] += sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
			if(C[i][j]==0 && i >= j)
				sum[i][j]++;
		}
		//sum[i][i+1] = sum[i][i];
	}
	while(t--){
		scanf("%d%d",&n,&m);
		if(n < m) m = n;
		printf("%d\n",sum[n][m]);
	}
    return 0;
}
