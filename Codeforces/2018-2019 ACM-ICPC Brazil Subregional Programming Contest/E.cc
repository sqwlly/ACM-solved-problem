/*************************************************************************
    > File Name: E.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年08月29日 星期四 10时30分48秒
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

//t[0] -> 0, n - m - 1
//t[1] -> 1, n - m 
//t[2] -> 2, n - m + 1
//t[3] -> 3, n - m + 2
//t[4] -> 4, n - m + 3
//...
//..
//.
//t[m] -> n - m - 1, n - m + m - 1 
const int N = 1E4+10;
int sum[250][N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	string s,t;
	cin >> s >> t;
	int n = s.length(), m = t.length();
	int ans = 0;
	for(int i = 0; i < n - m + 1; ++i) {
		bool ok = 1;
		for(int j = 0, k = i; j < m && k < n; ++j, ++k) {
			if(s[i + j] == t[j]) {
				ok = 0;
				break;
			}
		}
		if(ok) ans++;
	}
	cout << ans << endl;
    return 0;
}
