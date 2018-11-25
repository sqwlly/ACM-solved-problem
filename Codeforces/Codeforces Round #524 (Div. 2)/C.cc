/*************************************************************************
    > File Name: C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com
    > Created Time: 2018年11月24日 星期六 16时20分44秒
 ************************************************************************/

#include<bits/stdc++.h>
typedef long long LL;
using namespace std;

struct rec{
    int x1,y1,x2,y2;
    rec() {}
    rec(int a,int b,int c,int d) { x1 = a; y1 = b; x2 = c; y2 = d;}
};
int n,m;
bool comb(rec t)
{
    if(t.x1 <= t.x2 && t.y1 <= t.y2)
        return 1;
    return 0;
}

LL all(rec a)
{
    LL n = a.y2 - a.y1 + 1;
    LL m = a.x2 - a.x1 + 1;
    return n * m;
}

LL color_w(rec a)
{
    LL a_m = a.x2 - a.x1 + 1, a_n = a.y2 - a.y1 + 1;
    if((a.x1 + a.y1) % 2 == 0) {
        return ((a_m * a_n + 1)/ 2);
    }
    return  (a_m * a_n / 2);
}

LL color_b(rec a)
{
    return all(a) - color_w(a);
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
#endif
    int T;
    cin >> T;
    while (T--) {
        rec a, b;
        cin >> n >> m;
        cin >> a.x1 >> a.y1 >> a.x2 >> a.y2;
        cin >> b.x1 >> b.y1 >> b.x2 >> b.y2;
        LL sum_w = (1LL * n * m + 1) / 2;
        sum_w += color_b(a);
        sum_w -= color_w(b);
        rec t = rec{max(a.x1, b.x1), max(a.y1, b.y1), min(a.x2, b.x2), min(a.y2, b.y2)};
        if (comb(t) == 1) {
            sum_w -= color_b(t);
        }
        cout << sum_w << ' ' << 1LL * n * m - sum_w << endl;
    }
    return 0;
}

