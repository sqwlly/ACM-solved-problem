#include<bits/stdc++.h>
using namespace std;
int f[10010],n,p = 1e9+7;

int main()
{
    int t,k,a,b;
    scanf("%d",&t);
    while(t--)
    {
        memset(f,0,sizeof(f));
        f[0]=1;
        scanf("%d%d",&n,&k);
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            b = (1<<b)-1;
            for(int j=1;j <= b;j<<=1)
            {
                for(int l = 10010; l >= j*a; l--)
                {
                    f[l]=(f[l]%p+f[l-j*a]%p)%p;
                }
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
