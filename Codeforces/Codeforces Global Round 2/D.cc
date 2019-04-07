/*************************************************************************
    > File Name: D.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年04月07日 星期日 16时26分08秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
#define dbg(args...)                             \
    do                                           \
    {                                            \
        cout << "\033[32;1m" << #args << " -> "; \
        err(args);                               \
    } while (0)
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
/*************************************************************************************/
const int N = 1E5+10;
typedef long long LL;

LL s[N],len[N],sum[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	LL n,q,l,r;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> s[i];
	}
	sort(s + 1, s + 1 + n);
	for(int i = 1; i < n; ++i) {
		len[i] = s[i + 1] - s[i];
	}
	sort(len + 1, len + n);
	for(int i = 1; i < n; ++i) {
		sum[i] = sum[i - 1] + len[i];
	}
	cin >> q;
	for(int i = 0; i < q; ++i) {
		cin >> l >> r;
		LL v = r - l + 1;
		int d = upper_bound(len + 1, len + n, v) - len;
		LL ans = (n - d + 1) * v + sum[d - 1];
		cout << ans << ' ';
	}
    return 0;
}
