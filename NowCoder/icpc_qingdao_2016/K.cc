#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
const LL MAXN = 200010, DIM = 10;
inline LL sqr(LL x) { return x * x; }
namespace KDTree {
    LL K;
 
    struct PoLL {
        LL x[DIM], id;
 
        LL distance(const PoLL &b) const {
            LL ret = 0;
            for (LL i = 0; i < 2; ++i)
                ret += sqr(x[i] - b.x[i]);
            return ret;
        }
 
        void input(LL _id) {
            for (LL i = 0; i < K; ++i) scanf("%lld", &x[i]);
            id = _id;
        }
    };
 
    struct cmpx {
        LL div;
 
        cmpx(const LL &_div) { div = _div; }
 
        bool operator()(const PoLL &a, const PoLL &b) {
            for (LL i = 0; i < K - 1; ++i)
                if (a.x[(div + i) % K] != b.x[(div + i) % K])
                    return a.x[(div + i) % K] < b.x[(div + i) % K];
            return true;
        }
    };
 
    bool cmp(const PoLL &a, const PoLL &b, LL div) {
        cmpx cp = cmpx(div);
        return cp(a, b);
    }
 
    struct Node {
        PoLL e;
        Node *lc, *rc;
        LL div;
    } pool[MAXN], *tail, *root;
 
    void init() { tail = pool; }
 
    Node *build(PoLL *a, LL l, LL r, LL div) {
        if (l >= r) return NULL;
        Node *p = tail++;
        p->div = div;
        LL mid = (l + r) / 2;
        nth_element(a + l, a + mid, a + r, cmpx(div));
        p->e = a[mid];
        p->lc = build(a, l, mid, (div + 1) % K);
        p->rc = build(a, mid + 1, r, (div + 1) % K);
        return p;
    }
 
    LL minDis = 1e18, id = -1;
 
    void search(PoLL p, Node *x, LL div) {
        if (!x) return;
        if (x->e.x[2] <= p.x[2]) {
            LL dis = p.distance(x->e);
            if (dis < minDis || (dis == minDis && x->e.id < id)) {
                minDis = dis;
                id = x->e.id;
            }
        }
        if (div == 2) {
            if (cmp(p, x->e, div)) {
                search(p, x->lc, (div + 1) % K);
            } else {
                search(p, x->rc, (div + 1) % K);
                search(p, x->lc, (div + 1) % K);
            }
        } else {
            LL d = x->e.x[div] - p.x[div];
            if (cmp(p, x->e, div)) {
                search(p, x->lc, (div + 1) % K);
                if (minDis > d * d)
                    search(p, x->rc, (div + 1) % K);
            } else {
                search(p, x->rc, (div + 1) % K);
                if (minDis > d * d)
                    search(p, x->lc, (div + 1) % K);
            }
        }
    }
 
    void search(PoLL p) {
        search(p, root, 0);
    }
};
 
KDTree::PoLL p[MAXN],tmp[MAXN];
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
#endif
    KDTree::K = 3;
    int T, n, Q;
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d", &n, &Q);
        for (LL i = 0; i < n; ++i) {
            p[i].input(i);
            tmp[i] = p[i];
        }
        KDTree::init();
        KDTree::root = KDTree::build(p, 0, n, 0);
        KDTree::PoLL o;
        while (Q--) {
            o.input(0);
            KDTree::minDis = 1e18;
            KDTree::id = -1;
            KDTree::search(o);
            LL id = KDTree::id;
            printf("%lld %lld %lld\n", tmp[id].x[0], tmp[id].x[1], tmp[id].x[2]);
        }
    }
    return 0;
}
