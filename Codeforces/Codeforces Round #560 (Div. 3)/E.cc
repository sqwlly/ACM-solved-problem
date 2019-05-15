/*************************************************************************
    > File Name: E.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年05月15日 星期三 12时34分50秒
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
const int N = 2E5+10, mod = 998244353;
//pair<int,int> a[N],b[N];
typedef long long LL;
LL a[N],b[N];
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	//(1, 1) (1, 2) (2, 2)
	//4 + 4 + 6 + 6
	//1,1 1,2 1,3 1,4 .. 1,n  -->      n * (a[1] * b[1]) + (n - 1) * (a[2] * b[2]) + .. + a[n] * b[n]
	//    2,2 2,3 2,4 .. 2,n  -->                          (n - 1) * (a[2] * b[2]) + .. + a[n] * b[n]
	//        3,3 3,4 .. 3,n  -->                                                 
	//            4,4 .. 4,n
	//                    .
	//                    .
	//                   n,n
	//   n * a[n] * b[n] + (n - 1) * 2 * (a[n - 1] * b[n - 1]) + .. + n * a[1] * b[1]
	int n,x;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> x;
		a[i] = 1LL * (n - i) * x * (i + 1);
	}
	sort(a, a + n);
	for(int i = 0; i < n; ++i) {
		cin >> x;
		b[i] = x;
	}
	sort(b, b + n, greater<LL>());
	LL ans = 0;
	for(int i = 1, k = n; i <= n; ++i, --k) {
	//	dbg(i,k,n - i + 1);
		ans = (ans + a[i - 1] % mod * b[i - 1] % mod) % mod;
	}
	cout << ans << endl;
    return 0;
}
