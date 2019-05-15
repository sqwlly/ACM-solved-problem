/*************************************************************************
    > File Name: D_.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年05月15日 星期三 11时48分43秒
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
const int N = 302;
typedef long long LL;
LL a[N];
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int T,n;
	cin >> T;
	while(T--) {
		cin >> n;
		for(int i = 0; i < n; ++i) {
			cin >> a[i];
		}
		sort(a, a + n);
		LL ret = a[0] * a[n - 1];

		int ok = 1;
		for(int i = 1, j = n - 2; i <= j; ++i, --j) {
			if(a[i] * a[j] != ret) {
				ok = 0;
				break;
			}
		}
		int cnt = 0;
		for(LL i = 2; i * i <= ret && ok; ++i) {
			if(i * i == ret) cnt++;
			else if(ret % i == 0) {
				cnt += 2;
			}
		}
		cout << ((ok == 0 || cnt != n) ? -1 : ret) << endl;
	}
    return 0;
}
