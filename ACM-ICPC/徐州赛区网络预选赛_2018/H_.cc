/* @树状数组做法
 *
 * */
#include <bits/stdc++.h>
typedef long long LL;
const int N = 1e6+10;
LL sum[N];
LL Tangle[N];
int a[N],n;

inline int lowbit(int x)
{
        return x&(-x);
}

void update_Tangle(int x,LL v)
{
        while(x<=n)
        {
                Tangle[x]+=v;
                x += lowbit(x);
        }
}

void update_sum(int x,LL v)
{
        while(x<=n)
        {
                sum[x]+=v;
                x += lowbit(x);
        }
}

LL query_sum(int i)
{
        LL ret = 0;
        while(i>0)
        {
                ret += sum[i];
                i -= lowbit(i);
        }
        return ret;
}

LL query_Tangle(int i)
{
        LL ret = 0;
        while(i>0)
        {
                ret += Tangle[i];
                i -= lowbit(i);
        }
        return ret;
}
int main(int argc, char const *argv[]) {
        int q;
        scanf("%d%d", &n,&q);
        for(int i = 1; i <= n; ++i) {
                scanf("%d", &a[i]);
                update_sum(i,a[i]*1LL);
                update_Tangle(i,(n-i+1)*a[i]*1LL);
        }
        int op = 0,x,y;
        while(q--) {
                scanf("%d%d%d", &op,&x,&y);
                if(op==1) {
                        LL ans = query_Tangle(y)-query_Tangle(x-1)-1LL*(n-y)*(query_sum(y)-query_sum(x-1));
                        printf("%lld\n", ans);
                }else{
                        update_sum(x,-a[x]);
                        update_sum(x,y);
                        update_Tangle(x,-(n-x+1)*1LL*a[x]);
                        update_Tangle(x,(n-x+1)*1LL*y);
                        a[x] = y;
                }
        }
        return 0;
}

