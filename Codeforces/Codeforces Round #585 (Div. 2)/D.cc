/*************************************************************************
    > File Name: D.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年09月16日 星期一 10时07分19秒
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
	int n;
	cin >> n;
	string s;
	cin >> s;
	int cnt = 0;
	long double L = 0, R = 0;
	for(int i = 0; i < n; ++i) {
		if(s[i] != '?') {
			if(i < n / 2) L += (long double)(s[i] - '0');
			else R += (long double)(s[i] - '0');
		}else{
			if(i < n / 2) L += (long double)4.5;
			else R += (long double)4.5;
		}
	}
	cout << ((fabs(L - R) < 1e-9) ? "Bicarp" : "Monocarp") << '\n';
    return 0;
}
