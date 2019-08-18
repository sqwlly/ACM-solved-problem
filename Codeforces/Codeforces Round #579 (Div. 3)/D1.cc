/*************************************************************************
    > File Name: D1.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年08月18日 星期日 11时41分13秒
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
	string s,t;
	cin >> s >> t;
	int n = s.size(), ans = 0;
	for(int i = 0; i < n; ++i) {
		for(int j = i + 1; j <= n; ++j) {
			bool ok = 1;
			string q = s.substr(0,i) + s.substr(j,n - j);
		//	dbg(q);
			int w = 0;
			for(int k = 0; k < q.length(); ++k) {
				if(q[k] == t[w] && w < t.length()) {
					w++;
				}
			}
			if(w == t.length()) {
				ans = max(ans, j - i);
			}
		}
	}
	cout << ans << endl;
    return 0;
}
