/*************************************************************************
    > File Name: I.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com
    > Created Time: 2019年02月06日 星期三 20时34分11秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
//1 5 3 2 4
//0 1 0 0 1
//1 3 2 5 4
//0 0 0 1 1
typedef long long LL;
const int N = 2E5+10;
struct data{
    int Inc,nSum;
} tr[N << 2];
LL a[N], sum1[N], sum2[N], X;

void pushup(int rt)
{
    tr[rt].nSum = tr[rt << 1].nSum + tr[rt << 1 | 1].nSum;
}

void pushdown(int rt,int L,int R,int mid)
{
    if(tr[rt].Inc != -1) {
        tr[rt << 1].Inc = tr[rt].Inc;
        tr[rt << 1 | 1].Inc = tr[rt].Inc;
        tr[rt << 1].nSum = tr[rt].Inc * (mid - L + 1);
        tr[rt << 1 | 1].nSum = tr[rt].Inc * (R - mid);
        tr[rt].Inc = -1;
    }
}

void build(int rt,int x,int y)
{
    tr[rt].Inc = -1;
    if(x == y) {
        tr[rt].nSum = a[x] > X;
        return;
    }
    int m = (x + y) >> 1;
    build(rt << 1, x, m);
    build(rt << 1 | 1, m + 1, y);
    pushup(rt);
}

int query(int rt,int l,int r,int x,int y)
{
    if (x > y) return 0;
    if (l >= x && r <= y) return tr[rt].nSum;
    int m = (l + r) >> 1;
    pushdown(rt, l, r, m);
    int ret = 0;
    if (x <= m) ret += query(rt << 1, l, m, x, y);
    if (y > m) ret += query(rt << 1 | 1, m + 1, r, x, y);
    return ret;
}

void update(int rt,int l,int r,int x,int y, int v)
{
    if (l >= x && r <= y) {
        tr[rt].nSum = v * (r - l + 1);
        tr[rt].Inc = v;
        return;
    }
    int m = (l + r) >> 1;
    pushdown(rt, l, r, m);
    if (x <= m) update(rt << 1, l, m, x, y, v);
    if (y > m) update(rt << 1 | 1, m + 1, r, x, y, v);
    pushup(rt);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
#endif
    int n, q, p, l, r, k1 = 1, k2 = 1;
    cin >> n >> q >> X;
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", a + i);
        if (a[i] > X) {
            sum1[k1] = sum1[k1 - 1] + a[i];
            k1++;
        } else {
            sum2[k2] = sum2[k2 - 1] + a[i];
            k2++;
        }
    }
    build(1, 1, n);
    while (q--) {
        scanf("%d%d%d", &p, &l, &r);
        if (p == 1) {
            int y = query(1, 1, n, 1, r);
            int x = query(1, 1, n, 1, l - 1);
            LL ans = sum1[y] - sum1[x]; // > X
            ans += sum2[r - y] - sum2[l - 1 - x]; // <= X
            printf("%lld\n", ans);
        } else if (p == 2) {
            int one = query(1, 1, n, l, r);
            int zero = (r - l + 1) - one;
            update(1, 1, n, l, l + zero - 1, 0);
            update(1, 1, n, l + zero, r, 1);
        } else if (p == 3) {
            int one = query(1, 1, n, l, r);
            update(1, 1, n, l, l + one - 1, 1);
            update(1, 1, n, l + one, r, 0);
        }
    }
    return 0;
}

