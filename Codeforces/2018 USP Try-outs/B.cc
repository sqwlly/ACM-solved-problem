/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年09月03日 星期二 10时02分54秒
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
const int N = 2E3+10;
int a[N];
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n, ans = INT_MAX;
	cin >> n;
	for(int i = 0; i < n; ++i) cin >> a[i];
	for(int i = 2; i  <= n; ++i) {
		if(n % i == 0) {
			int k = n / i, cnt = 0;
			map<int,int> g;
			for(int j = 0; j < n; ++j) {
				g[a[j] % i]++;
			}
			bool ok = 1;
			for(int j = 0; j < i; ++j) {
				if(g[j] != k) {
					ok = 0;
					break;
				}
			}
			if(ok) {
				return cout << i << '\n',0;
			}
		}
	}
	cout << -1 << '\n';
    return 0;
}
