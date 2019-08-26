/*************************************************************************
    > File Name: E.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年08月24日 星期六 10时10分34秒
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
const LL MAX = 1E12;
void solve(LL a,LL b,LL c,LL d)
{
	LL cnt = 0;
	for(int i = 1; i < 1000; ++i) {
		for(int j = 1; j < 1000; ++j) {
			if(__gcd(i,j) == 1 && (i + j) < 1000) {
				LL x = (LL)ceil(1.0 * a / i), y = (LL)floor(1.0 * b / i), l = (LL)ceil(1.0 * c / j), r = (LL)floor(1.0 * d / j);
				LL X = max(x, l);
				LL Y = min(y, r);
				if(X <= Y) cnt += Y - X + 1;
			}
		}
	}
	cout << cnt << endl;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	LL A,B,C,D;
	cin >> A >> B >> C >> D;
	solve(A,B,C,D);
    return 0;
}
