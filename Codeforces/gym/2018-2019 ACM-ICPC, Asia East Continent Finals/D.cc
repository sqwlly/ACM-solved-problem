/*************************************************************************
    > File Name: D.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年10月20日 星期日 10时09分36秒
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
	int T,n,m;
	cin >> T;
	while(T--) {
		cin >> n >> m;
		long long x = 0, y = 0, v;
		for(int i = 0; i < n; ++i) {
			cin >> v;
			x += v;
		}
		for(int i = 0; i < m; ++i) {
			cin >> y;
			y += v;
		}
		if(n <= m) {
			cout << "Yes" << '\n';
		}else{
			cout << "No" << '\n';
		}
	}
    return 0;
}
