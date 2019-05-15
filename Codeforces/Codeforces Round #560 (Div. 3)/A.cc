/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年05月14日 星期二 22时17分04秒
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

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,x,y;
	cin >> n >> x >> y;
	string s;
	cin >> s;
	int cnt = 0;
	for(int i = 1; i <= y; ++i) {
		if(s[n - i] != '0') cnt++;
	}
	if(s[n - y - 1] != '1') cnt++;
//	dbg(cnt);
//	if(s[n - x - 1] != '1') cnt++;
	for(int i = n - x, k = 0; i < n - y - 1; ++i) {
		if(s[i] != '0') cnt++;
	}
	cout << cnt << endl;
    return 0;
}
