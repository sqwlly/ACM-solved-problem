#include<cstdio>
int n,ans;
int main()
{
    scanf("%d",&n);
    for(int i=1,j;i<=n;i=j+1)//节约时间
    {
        j=n/(n/i);
        ans+=(n/i)*(j*(j+1)/2-i*(i-1)/2);
    }
	//
    printf("%d\n",ans);
	int a = 0;
	for(int i = 1; i <= n; ++i) {
		a += (n / i) * i;
	}
	printf("%d\n",a);
    return 0;
}

