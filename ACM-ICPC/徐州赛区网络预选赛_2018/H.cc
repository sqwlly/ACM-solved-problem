/* @ H.cc 线段树维护两个前缀和
 * 题解：https://blog.csdn.net/Eternally831143/article/details/82563822
 *
 * */
#include <cstdio>
typedef long long LL;
using namespace std;
const int N = 1e6+4;
int n,q,a[N];
struct data {
        int l,r;
        LL val,tangle;
} tr[N<<1];

void pushup(int rt)
{
        tr[rt].val=tr[rt<<1].val+tr[rt<<1|1].val;
        tr[rt].tangle=tr[rt<<1].tangle+tr[rt<<1|1].tangle;
}

void build(int k,int s,int t) {//建树
        tr[k].l=s; tr[k].r=t;
        if(s==t) {
                tr[k].val = a[s];
                tr[k].tangle = a[s]*1LL*(n-s+1);
                return;
        }
        int mid=(s+t)>>1;
        build(k<<1,s,mid);
        build(k<<1|1,mid+1,t);
        pushup(k);
}

LL query(int k,int x,int y,int len){//区间求和
        int L=tr[k].l,R=tr[k].r;
        if(x==L && y==R)
                return tr[k].tangle-1LL*len*tr[k].val;
        int mid=(L+R)>>1;
        if(y<=mid)
                return query(k<<1,x,y,len);
        else if(x>mid)
                return query(k<<1|1,x,y,len);
        else
                return query(k<<1,x,mid,len)+query(k<<1|1,mid+1,y,len);
}

void update(int rt,int L,int R,int x,LL v)
{
        if(L == R) {
                tr[rt].tangle = (n-x+1)*1LL*v;
                tr[rt].val = v;
                return;
        }
        int mid = (L + R) >> 1;
        if(x <= mid)
                update(rt << 1, L, mid, x, v);
        else
                update(rt << 1 | 1, mid + 1, R, x, v);
        pushup(rt);
}


int main(){
        scanf("%d%d",&n,&q);
        for(int i=1; i<=n; i++)
                scanf("%d",&a[i]);
        build(1,1,n);
        int op,x,y;
        for(int i=1; i<=q; i++) {
                scanf("%d%d%d",&op,&x,&y);
                if(op==2)
                        update(1,1,n,x,y);
                else
                        printf("%lld\n", query(1,x,y,n-y));
        }
        return 0;
}

