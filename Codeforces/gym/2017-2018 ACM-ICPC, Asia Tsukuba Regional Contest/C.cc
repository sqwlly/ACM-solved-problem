/*************************************************************************
    > File Name: C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年09月11日 星期三 10时21分17秒
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
const int N = 1E5+10;
typedef long long LL;
LL h[N],sum[N];
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	LL n,t;
	cin >> n >> t;
	for(int i = 1; i <= n; ++i) {
		cin >> h[i];
		sum[i] = sum[i - 1] + h[i];
	}
	LL x, last = 0, complete = 0, cur;

	for(int i = 1; i <= n; ++i) {
		x = (t - sum[i - 1]) / h[i] + 1;
		if(t - sum[i - 1] <= 0) x = 1;
		if(i == 1) {
			last = x + 1;
			complete = sum[i - 1] + (t - sum[i - 1]) / h[i] * h[i];
		}
		if(i >= 2) {
			cur = sum[i - 1] + (t - sum[i - 1]) / h[i] * h[i];
			dbg(cur,complete, t - complete, complete - cur);
			if(cur > complete) last--;
		}
		cout << min(last, x) << '\n';
		last = min(last, x);
		complete = sum[i - 1] + (t - sum[i - 1]) / h[i] * h[i];
	}
    return 0;
}
