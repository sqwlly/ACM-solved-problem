/*************************************************************************
    > File Name: E.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com
    > Created Time: 2019年03月20日 星期三 17时36分22秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
typedef long long LL;
using namespace std;
const int N = 2E5+10;
LL sum[N],d[N],n,H;

bool ok(LL x,LL & ans)
{
    x--;
    ans = n + 1;
    LL res = H + x * sum[n];
    for(int i = 1; i <= n; ++i) {
        if(res + sum[i] <= 0) {
            ans = i;
            return 1;
        }
    }
    return res <= 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> H >> n;
    for(int i = 1; i <= n; ++i) {
        cin >> d[i];
        sum[i] = sum[i - 1] + d[i];
    }
    LL l = 1, r = 1;
    if(sum[n] != 0) {
        r = max(r, -H / sum[n] + 1);
    }
    LL ans = -1, dx = n;
    while(l <= r) {
        LL mid = l + r >> 1;
        if(ok(mid, dx)) {
            ans = (mid - 1) * n + dx;
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}

