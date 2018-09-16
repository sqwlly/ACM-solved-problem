#include<bits/stdc++.h>
using namespace std;
int f[10010],n,p = 1e9+7;
int V[10010];
struct node{
    int v,cnt;
}num[21];

int binary()
{
    int k = 1;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= num[i].cnt; j <<= 1){
            V[k++] = j*num[i].v;
            num[i].cnt -= j;
        }
        if(num[i].cnt > 0)
            V[k++] = num[i].cnt * num[i].v;
    }
    return k;
}

int main()
{
    int t,k,a,b;
    scanf("%d",&t);
    while(t--)
    {
        memset(f,0,sizeof(f));
        f[0]=1;
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&a,&b);
			num[i].v = a;
			num[i].cnt = (1<<b)-1;
        }
		int cnt = binary();
		//printf("%d\n",cnt);
		for(int i = 1; i < cnt; ++i){
			for(int j = 10010; j >= V[i]; --j){
				f[j] = (f[j]%p + f[j-V[i]]%p)%p;
			}
		}
        int w;
        for(int i = 0; i < k; ++i){
            scanf("%d",&w);
            printf("%d\n",f[w]);
        }
    }
    return 0;
}


