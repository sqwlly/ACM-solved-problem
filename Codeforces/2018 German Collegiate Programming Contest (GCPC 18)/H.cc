/*************************************************************************
    > File Name: H.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年08月26日 星期一 12时35分12秒
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
long long quick(long long a,long long n)
{
	long long res = 1;
	while(n > 0) {
		if(n & 1) res = res * a;
		a *= a;
		n >>= 1;
	}
	return res;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	long long m,sum;
	cin >> m;
	for(int s = 1; s <= 54; ++s) {
		sum = 0;
		for(int n = 1; n; ++n) {
			long long t = quick(n,s);
			if(t <= 0) break;
			sum += t;
			if(sum == m && s + 1 >= 3) {
				return cout << s + 1 << ' ' << n << endl,0;
			}
			if(sum > m) break;
			if(sum <= 0) break;
		}
	}
	cout << "impossible" << endl;
    return 0;
}
