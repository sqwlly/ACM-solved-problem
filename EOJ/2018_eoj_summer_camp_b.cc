/*************************************************************************
    > File Name: 2018_eoj_summer_camp_b.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com
    > Created Time: 2019年03月12日 星期二 08时02分40秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 5E6+10;
int tr[N << 2], add[N << 2], hsh[N << 2];

struct node{
    int l, r;
    bool operator < (const node & u) const {
        return l < u.l;
    }
}a[N];

void pushup(int rt)
{
    tr[rt] = max(tr[rt << 1],tr[rt << 1 | 1]);
}

void pushdown(int rt)
{
    if(add[rt]) {
        add[rt << 1] += add[rt];
        add[rt << 1 | 1] += add[rt];
        tr[rt << 1] += add[rt];
        tr[rt << 1 | 1] += add[rt];
        add[rt] = 0;
    }
}

void update(int rt,int l,int r,int x,int y,int z)
{
    if(x <= l && r <= y) {
        tr[rt] += z;
        add[rt] += z;
        return;
    }
    int mid = l + r >> 1;
    pushdown(rt);
    if(x <= mid) update(rt << 1, l, mid, x, y, z);
    if(y > mid) update(rt << 1 | 1, mid + 1, r, x, y, z);
    pushup(rt);
}

int query(int rt,int l,int r,int x,int y)
{
    if(x <= l && r <= y) {
        return tr[rt];
    }
    int mid = l + r >> 1;
    pushdown(rt);
    int ret = 0;
    if(x <= mid)
        ret = max(ret, query(rt << 1, l, mid, x, y));
    if(y > mid)
        ret = max(ret, query(rt << 1 | 1, mid + 1, r, x, y));
    return ret;
}

vector<int> v;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m,L,tot = 1;
    long long len = 0;
    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        cin >> a[i].l >> a[i].r;
        L = max(L, a[i].r);
        len += a[i].r - a[i].l + 1;
        hsh[tot++] = a[i].l;
        hsh[tot++] = a[i].r;
    }
    sort(a, a + n);
    int k = unique(hsh + 1, hsh + tot + 1) - hsh;
    int t = k;
    for(int i = 1; i <= t; ++i) {
        if(hsh[i] - hsh[i - 1] > 1)
            hsh[k++] = hsh[i - 1] + 1;
    }
    sort(hsh + 1, hsh + k + 1);
    int ans = 0;
    for(int i = 0; i < n; ++i) {
        int l = lower_bound(hsh + 1, hsh + k + 1, a[i].l) - hsh;
        int r = lower_bound(hsh + 1, hsh + k + 1, a[i].r) - hsh;
        update(1, 1, k, l, r, 1);
        ans = max(ans, query(1, 1, k, 1, k));
    }
    long long tmp = __gcd(m * 1LL, len);
    long long fa = len / tmp, fb = m / tmp;
    int op;
    cin >> op;
    if(op == 1) {
        cout << ans << endl;
    }else if(op == 2) {
        cout << fa << "/" << fb;
    }else if(op == 3) {
        cout << ans << endl;
        cout << fa << "/" << fb << endl;
    }
    return 0;
}

