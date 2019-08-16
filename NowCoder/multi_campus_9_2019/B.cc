/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年08月15日 星期四 12时24分45秒
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
	//(x + y)^2 % p = x^2 + y^2 + 2xy = b^2 % p
	//            x^2 + y^2 + 2c = b^2 % p
	//(x - y)^2 % p = x^2 + y^2 - 2xy
	//              = b^2 - 2c - 2c
	//
	//(x + y) % p = b
	//(x * y) % p = c;
	//
	//(x + y) % p = b 
	//
	//b^2 = (x + y) % p * (x + y) % p = (x + y)^2 % p 
	//						    = (x^2 + y^2 + 2xy) % p
	//						    = x^2 % p + y^2 % p + 2xy % p = b^2
	//						
	//							b^2 - 2c = x^2 % p + y^2 % p
	//
	//(x - y)^2 % p = (x^2 + y^2 - 2xy) % p
	//				= x^2 % p + y^2 % p - 2xy % p
	//				= b^2 - 4c
	//
	//p - (x + y) / p
	//

	//
    return 0;
}
