/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年09月15日 星期日 18时31分53秒
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
	int a1,a2,k1,k2,n,c,t;
	cin >> a1 >> a2 >> k1 >> k2 >> n;
	if(k1 < k2) {
		c = n / k1;
		c = min(c, a1);
		t = n - c * k1;
	}else{
		c = n / k2;
		c = min(c, a2);
		t = n - c * k2;
	}
	c += t / max(k1,k2);
	int r = (k1 - 1) * a1 + (k2 - 1) * a2;
	r = max(n - r, 0);
	c = min(c, a1 + a2);
	cout << r << ' ' << c << endl;
    return 0;
}
