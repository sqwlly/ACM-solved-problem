/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年09月10日 星期二 09时04分52秒
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
    //ios::sync_with_stdio(false); cin.tie(0);
    freopen("hamming.in","r",stdin);
	int T;
	cin >> T;
	string s,b;
	int n;
	while(T--) {
		cin >> n >> s >> b;
		sort(s.begin(),s.end());
		sort(b.begin(),b.end(),greater<int>());
		dbg(s);
		dbg(b);
		int cnt = 0;
		for(int i = 0; i < n; ++i) {
			cnt += ((s[i] - '0') ^ (b[i] - '0'));
		}
		cout << cnt << '\n';
	}
    return 0;
}
