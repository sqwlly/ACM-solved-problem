/*************************************************************************
    > File Name: C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年08月23日 星期五 09时58分26秒
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
typedef long long LL;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int T,n,a,b;
	string s;
	cin >> T;
	while(T--) {
		cin >> n >> a >> b >> s;
		s += '0';
		bool start = 0;
		LL ans = b;
		for(int i = 0; i < n; ++i) {
			ans += b + a;
			if(s[i + 1] == '1' || (s[i] == '1'  && s[i + 1] == '0' && s[i + 2] == '1')){ 
				ans += b;
				if(start == 0) {
					ans += a, start = 1;
			//		dbg(start);
				}
			//	dbg(ans,i,s[i]);
			} else {
				if(start == 1) {
					ans += a + b;
					if(a == b && i != n - 2) ans -= a;
				}
			//	dbg(ans,i,s[i]);
				start = 0;
			//	dbg(start);
			}
		}
		cout << ans << endl;
	}
    return 0;
}
