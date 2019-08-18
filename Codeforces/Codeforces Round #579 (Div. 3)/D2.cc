/*************************************************************************
    > File Name: D2.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年08月18日 星期日 14时58分34秒
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
const int N = 2E5+10;
int L[N], R[N];
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	string s,t;
	cin >> s >> t;
	int k = 0, n = s.size(), m = t.size();
	int last, first = -1, ans = 0;
	for(int i = 0; i < n; ++i) {
		if(s[i] == t[k] && k < m) {
			L[k] = i;
			k++;
		}else if(k == m) {
			break;
		}
	}
	k = m - 1; first = -1;
	for(int i = n - 1; i >= 0; --i) {
		if(s[i] == t[k] && k >= 0) {
			R[k] = i;
			k--;
		}else if(k == -1) {
			break;
		}
	}//01234   
	// aabac
	// ac
	ans = max(R[0], n - L[m - 1] - 1);
	for(int i = 1; i < m; ++i) {
		ans = max(ans, R[i] - L[i - 1] - 1);
	}
	cout << ans << endl;
    return 0;
}
