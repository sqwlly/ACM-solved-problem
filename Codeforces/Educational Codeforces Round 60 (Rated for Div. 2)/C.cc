/*************************************************************************
    > File Name: C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com
    > Created Time: 2019年02月19日 星期二 18时32分43秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
typedef long long LL;
using namespace std;
const int N = 1E5 + 10;
LL x[N],y[N],x_,x2,y_,y2,n;
string s;
bool ok(LL d)
{
    LL tx = x_ + d / n * x[n] + x[d % n];
    LL ty = y_ + d / n * y[n] + y[d % n];
    return abs(tx - x2) + abs(ty - y2) > d;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> x_ >> y_ >> x2 >> y2;
    cin >> n;
    cin >> s;
    for (int i = 1; i <= n; ++i) {
        char c = s[i - 1];
        x[i] = x[i - 1], y[i] = y[i - 1];
        if (c == 'L') {
            x[i]--;
        } else if (c == 'R') {
            x[i]++;
        } else if (c == 'U') {
            y[i]++;
        } else {
            y[i]--;
        }
    }

    LL l = 0, r = LLONG_MAX / 2, ans = -1;
    while (l <= r) {
        LL mid = (l + r) >> 1;
        if (ok(mid)) {
            l = mid + 1;
        } else {
            r = mid - 1;
            ans = mid;
        }
    }
    cout << ans << endl;
    return 0;
}

