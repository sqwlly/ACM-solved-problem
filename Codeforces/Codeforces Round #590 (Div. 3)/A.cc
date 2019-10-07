/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年10月01日 星期二 22时36分32秒
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

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int q,n;
	cin >> q;
	while(q--) {
		cin >> n;
		int a[102] = {0};
		long long sum = 0;
		for(int i = 0; i < n; ++i) {
			cin >> a[i];
			sum += a[i];
		}
		long long l = 1, r = sum;
		while(l <= r) {
			long long mid = l + r >> 1;
			if(mid * n < sum) {
				l = mid + 1;
			}else{
				r = mid - 1;
			}
		}
		cout << max(0LL,l) << endl;
	}
    return 0;
}
