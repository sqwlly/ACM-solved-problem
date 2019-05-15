/*************************************************************************
    > File Name: D.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年05月16日 星期四 00时05分41秒
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
const int N = 2E5+10;
int n,loc[N];
string s;
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> s;
	int dep = 1;
	for(int i = 0; i < n; ++i) {
		if(s[i] == '(') {
			loc[i] = dep++;
		}else{
			loc[i] = --dep;
		}
	}
	int maxdep = *max_element(loc, loc + n);
	int gap = maxdep / 2;
	for(int i = 0; i < n; ++i) {
		if(loc[i] > gap) cout << "0";
		else cout << 1;
	}
    return 0;
}
