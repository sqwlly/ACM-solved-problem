/*************************************************************************
    > File Name: bzoj1968.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年08月09日 星期五 10时09分48秒
 ************************************************************************/

#include<iostream>
using namespace std;
/*
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
}*/
/****************************************************************************************************/


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n, j = 0;
	cin >> n;
	long long ans = 0;
	for(int i = 1; i <= n; ) {
		j = n / (n / i);
		ans += (j - i + 1) * (i + j) / 2 * (n / i);
		i = j + 1;
	}
	cout << ans << endl;
    return 0;
}
