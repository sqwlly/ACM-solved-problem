/*************************************************************************
    > File Name: E.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年08月26日 星期一 10时18分54秒
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
bool isPrime(long long n)
{
	for(long long i = 2; i * i <= n; ++i) if(n % i == 0) return 0;
	return n != 1;
}
 
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		double a,b;
		cin >> a >> b;
		a *= 1000000, b *= 1000000;
		long long A = a+0.00001, B = b+0.00001;
		long long g = __gcd(A,B);
		A /= g, B /= g;
		if(A == B) A = B = 2;
		if(isPrime(A) == 0 || isPrime(B) == 0) cout << "impossible" << endl;
		else cout << A << ' ' << B << endl;
	}
    return 0;
}
