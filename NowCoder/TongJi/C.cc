/*************************************************************************
    > File Name: C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com
    > Created Time: 2019年04月20日 星期六 20时48分36秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
typedef long long LL;
using namespace std;
const int N = 1E5+10;
LL prime[N], k; bool vis[N];
bool is_Prime[N];
void init()
{
    for(int i = 2; i < N; ++i) {
        if(vis[i] == 0) {
            prime[k++] = i;
        }
        for(int j = 0; j < k && i * prime[j] < N; ++j) {
            vis[i * prime[j]] = 1;
            if(i % prime[j] == 0) break;
        }
    }
}

void segment_sieve(LL x, LL y)
{
    for(LL j = 0, i; j < k; ++j) {
        i = prime[j];
        for(LL r = max(2LL,(x + i - 1) / i) * i; r <= y; r += i)
            is_Prime[r - x] = 1;
    }
}
bool isPrime(LL n)
{
    if(n < (LL)1e5) return !vis[n];
    for(int i = 0; i < k && prime[i] * prime[i] <= n; ++i) {
        if(n % prime[i] == 0) return 0;
    }
    return n != 1;
}
LL ans[N][3],p;
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
#endif
    // ios::sync_with_stdio(false); cin.tie(0);
    LL l, r;
    init();
    scanf("%lld%lld", &l, &r);
    segment_sieve(l, r);
    for (LL d = l; d <= r; ++d) {
        if (is_Prime[d - l] == 0) continue;
        for (int i = 0; i < k && prime[i] * prime[i] <= d; ++i) {
            if (d % prime[i] == 0) {
                if (isPrime(d / prime[i]) == 1) {
                    ans[p][0] = d;
                    ans[p][1] = prime[i];
                    ans[p][2] = d / prime[i];
                    p++;
                }
                break;
            }
        }
    }
    printf("%d\n", p);
    for (int i = 0; i < p; ++i) {
        printf("%lld %lld %lld\n", ans[i][0], ans[i][1], ans[i][2]);
    }
    return 0;
}
