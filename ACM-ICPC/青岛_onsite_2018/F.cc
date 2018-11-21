/*************************************************************************
    > File Name: F.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年11月21日 星期三 23时38分59秒
 ************************************************************************/
#include<bits/stdc++.h>
#define ll long long
#define maxn 200010
using namespace std;
int n,m,k;
int main()
{
    int T,cas=1;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d",&n,&m);
        if(m>=(n&(-n))) {puts("Impossible");continue;}
        for(int j=1;j<=m;j++)
        for(int i=0;i<n;i++)
        {
            printf("%d%c",(i^j)+1,i==n-1?'\n':' ');
        }
    }
    return 0;
}

