/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年08月18日 星期日 11时09分22秒
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
		n *= 4;
		int x,a[500] = {0},cnt[10100] = {0};
		for(int i = 0; i < n; ++i) {
			cin >> x;
			cnt[x]++;
			a[i] = x;
		}
		sort(a, a + n);
		bool ok = 1;

		for(int i = 0; i < n; ++i) {
			if(cnt[a[i]] & 1) {
				ok = 0;
				break;
			}
		}	
		if(!ok) {
			cout << "NO" << endl;
			continue;
		}
		int ret = a[0] * a[n - 1];
		for(int i = 1; i < n - 1; ++i) {
			if(a[i] * a[n - i - 1] != ret) {
				ok = 0;
				break;
			}
		}
		cout << (ok ? "YES" : "NO") << endl;
	}
    return 0;
}
