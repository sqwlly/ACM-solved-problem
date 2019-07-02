/*************************************************************************
    > File Name: D.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com
    > Created Time: 2019年06月29日 星期六 16时03分40秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(args...)                                   \
    do{                                                \
	        cout << "\033[32;1m" << #args << " -> ";   \
         err(args);                                    \
      } while(0)
#else
#define dbg(...)
#endif
void err()
{
    cout << "\033[39;0m" << endl;
}
template <template <typename...> class T, typename t, typename... Args>
void err(T<t> a, Args... args)
{
    for (auto x : a) cout << x << ' ';
    err(args...);
}
template <typename T, typename... Args>
void err(T a, Args... args)
{
    cout << a << ' ';
    err(args...);
}
/****************************************************************************************************/
typedef long long LL;

bool check(LL x,int k,LL a[],LL b, LL m)
{
    LL sum = x;
    for(int i = 0; i < k; ++i) {
        sum += a[i];
    }
    if(sum == b) {
        return 1;
    }
    LL t = 0;
    for(int i = 0; i < k; ++i) {
        t += a[i];
    }
    if(t + sum + 1 > b) {
        return 0;
    }
    return 1;
}

void solve(LL a,LL b,LL m)
{
    int k = 1;
    vector<LL> ret;
    LL sum[55] = {a};
    while(sum[k - 1] < b) {
        LL ans = 0, l = 1, r = m;
        while(l <= r) {
            LL mid = l + r >> 1;
            if(check(mid,k,sum,b,m)) {
                l = mid + 1;
                ans = max(ans, mid);
            }else{
                r = mid - 1;
            }
        }
        for(int i = 0; i < k; ++i) {
            sum[k] += sum[i];
        }
        sum[k] += ans;
        k++;
        if(k > 50) {
            cout << -1 << endl;
            return;
        }
    }
    if(sum[k - 1] != b) {
        cout << -1 << endl;
        return;
    }
    cout << k << ' ';
    for(int i = 0; i < k; ++i) {
        cout << sum[i] << (i == k - 1 ? '\n' : ' ');
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
    LL q,a,b,m;
    cin >> q;
    while(q--) {
        cin >> a >> b >> m;
        solve(a,b,m);
    }
    return 0;
}

