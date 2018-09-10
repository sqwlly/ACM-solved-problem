/* 维护前缀和的前缀和
 * */

#include <cstdio>
#define L tree[rt].l
#define R tree[rt].r
typedef long long LL;
using namespace std;
const int N = 1e6+4;
int a[N],n,q;
LL sum[N];
struct data {
        int l,r;
        LL Inc,nSum;
} tree[N<<3];

void pushup(int rt)
{
        tree[rt].nSum = tree[rt<<1].nSum+tree[rt<<1|1].nSum;
}

void pushdown(int rt) {
        if(tree[rt].Inc) {
                int mid = (L+R)>>1;
                tree[rt<<1].Inc += tree[rt].Inc;
                tree[rt<<1|1].Inc += tree[rt].Inc;
                tree[rt<<1].nSum += tree[rt].Inc*(mid-L+1);
                tree[rt<<1|1].nSum += tree[rt].Inc*(R-mid);
                tree[rt].Inc = 0;
        }
}

void build(int rt,int x,int y) {//建树
        tree[rt].l = x; tree[rt].r = y;
        if(x == y) {
                tree[rt].Inc = 0;
                tree[rt].nSum = sum[x];
                return;
        }
        int mid = (x + y) >> 1;
        build(rt<<1,x,mid);
        build(rt<<1|1,mid+1,y);
        pushup(rt);
}

LL query(int rt,int x,int y){//区间求和
        if(x == L && y == R)
                return tree[rt].nSum;
        pushdown(rt);
        int mid=(L+R)>>1;
        if(y<=mid)
                return query(rt<<1,x,y);
        else if(x>mid)
                return query(rt<<1|1,x,y);
        else
                return query(rt<<1,x,mid)+query(rt<<1|1,mid+1,y);
}

void update(int rt,int x,int y,LL v)
{
        if(x == L && R == y) {
                tree[rt].nSum += v*1LL*(R-L+1);
                tree[rt].Inc += v;
                return;
        }
        pushdown(rt);
        int mid = (L+R)>>1;
        if(y <= mid)
                update(rt << 1, x, y,v);
        else if(x > mid)
                update(rt << 1 | 1, x, y,v);
        else{
                update(rt << 1, x, mid,v);
                update(rt << 1 | 1, mid+1, y,v);
        }
        pushup(rt);
}


int main(){
        scanf("%d%d",&n,&q);
        for(int i=1; i<=n; i++) {
                scanf("%d",&a[i]);
                sum[i] = sum[i-1] + a[i];
        }
        build(1,1,n);
        int op,x,y;
        for(int i=1; i<=q; i++) {
                scanf("%d%d%d",&op,&x,&y);
                if(op==2) {
                        update(1,x,n,1LL*(y-a[x]));
                        a[x] = y;
                }
                else{
                        if(x==1) {
                                printf("%lld\n", query(1,x,y));
                        }else
                        printf("%lld\n", query(1,x,y)-1LL*(y-x+1)*query(1,x-1,x-1));
                }
        }
        return 0;
}

