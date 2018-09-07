/* @ G.cc
 * 查找区间第一个大于等于v位置的模板
 * 这里因为题意要求找第一个小于v的，所以
 * 变成-v即可。
 * */
#include<bits/stdc++.h>
#define mid ((L + R) >> 1)
const int N = 1E5+10, inf = 1e9;
int a[N],max[N << 2],cnt[N],ret[N],n,m,q;

void build(int rt,int L,int R) {
    if (L == R) {
        max[rt] = -a[L];
        return;
    }
    build(rt << 1, L, mid);
    build(rt << 1 | 1, mid + 1, R);
    max[rt] = std::max(max[rt << 1], max[rt << 1 | 1]);
}

void update(int rt,int L,int R,int pos,int v) {
    if (L == R) {
        max[rt] = v;
        return;
    }
    if (pos <= mid)
        update(rt << 1, L, mid, pos, v);
    else
        update(rt << 1 | 1, mid + 1, R, pos, v);
    max[rt] = std::max(max[rt << 1], max[rt << 1 | 1]);
}

int query(int rt, int L, int R,int l,int r,int v) {
    if (L == R)
        return max[rt] >= v ? L : -1;
    if (L >= l && R <= r && max[rt] < v)
        return -1;
    if (r <= mid) return query(rt << 1, L, mid, l, r, v);
    if (l > mid) return query(rt << 1 | 1, mid + 1, R, l, r, v);
    int d = query(rt << 1, L, mid, l, mid, v);
    return d == -1 ? query(rt << 1 | 1, mid + 1, R, mid + 1, r, v) : d;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a + i);
    build(1, 1, n);
    scanf("%d", &q);
    std::vector<int> Q(q + 1);
    for (int i = 0; i < q; ++i)
        scanf("%d", &Q[i]);
    int maxM = *std::max_element(Q.begin(), Q.end());
    int cur = 0, d = 0, pos = -1;
    for (int i = 1; i <= maxM; ++i) {
        if (d < n) cur += m;
        int get = 0;
        pos = query(1, 1, n, 1, n, -cur);
        while (pos != -1) {
            get++, d++;
            cur -= a[pos];
            update(1, 1, n, pos, -inf);
            pos = query(1, 1, n, 1, n, -cur);
        }
        cnt[i] = cnt[i - 1] + get;
        ret[i] = cur;
    }
    for (int i = 0; i < q; ++i)
        printf("%d %d\n", cnt[Q[i]], ret[Q[i]]);
    return 0;
}

