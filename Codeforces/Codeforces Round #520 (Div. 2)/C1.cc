#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
const long long mod=1000000007;
char s[maxn];
long long a[maxn],sum[maxn];
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	a[0]=1;
	long long p=1;
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+(s[i]=='1');
		a[i]=(a[i-1]*2)%mod;
	}
	for(int i=1;i<=m;i++){
		long long x,y;
		long long ans=0;
		scanf("%lld%lld",&x,&y);
		long long num=sum[y]-sum[x-1];
		long long now=(a[num]-1+mod)%mod;
		long long t=y-x+1-num;
		ans=(now*(a[t]-1+mod))%mod;
		ans=(ans+now)%mod;
		printf("%lld\n",ans);
	}
}
