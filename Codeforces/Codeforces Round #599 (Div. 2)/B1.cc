/*************************************************************************
    > File Name: B1.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年11月12日 星期二 09时43分21秒
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
	int T;
	cin >> T;
	while(T--) {
		int n;
		string s,t;
		cin >> n >> s >> t;
		int k = 0, r1 = 0, r2 = 0;
		bool ok = 1;
		for(int i = 0; i < n; ++i) if(s[i] != t[i]) k++, r1 ^= s[i], r2 ^= t[i];
		if(k == 1 || k > 2 || r1 || r2) {
			ok = 0;
		}
		cout << (ok ? "Yes" : "No") << '\n';
	}
    return 0;
}
