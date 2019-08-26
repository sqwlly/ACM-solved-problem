/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年08月23日 星期五 09时21分25秒
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
	int T,b,p,f,h,c;
	cin >> T;
	while(T--) {
		cin >> b >> p >> f >> h >> c;
		int maxb = b / 2;
		int ans = 0;
		for(int i = 0; i <= maxb; ++i) {
			int t = min(i,p) * h;
			for(int j = 0; j <= maxb - i; ++j) {
				ans = max(ans, t + min(j,f) * c);
			}
		}
		cout << ans << endl;
	}
    return 0;
}
