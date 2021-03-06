/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年08月19日 星期一 21时04分03秒
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

string a("COFFEE"), b("CHICKEN");

LL size[70];

char solve(int n,LL k)
{
	if(n == 1) {
		if(k <= 6) return a[k - 1];
		else return ' ';
	}else if(n == 2) {
		if(k <= 7) return b[k - 1];
		else return ' ';
	}
	if(k <= size[n - 2]) return solve(n - 2, k);
	else return solve(n - 1, k - size[n - 2]);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int T,n; LL k;
	size[1] = 6; size[2] = 7;
	for(int i = 3; i <= 60; ++i) size[i] = size[i - 1] + size[i - 2];
	cin >> T;
	while(T--) {
		cin >> n >> k;
		if(n > 60) n = 60;
		for(LL d = k; d < k + 10; ++d) {
			if(d <= size[n]) cout << solve(n, d);
		}
		cout << endl;
	}
    return 0;
}
