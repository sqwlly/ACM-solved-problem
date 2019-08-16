/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年08月01日 星期四 12时05分17秒
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
const int N = 101;
string ans;

bool ok(string s)
{
	int k = s.length();
	for(int i = k - 1; i >= 0; --i) {
		
	}
}
/*
void dfs(int cur,int sum,string s,int len)
{
	if(len > 1e4) return;
	if(sum % n == 0 && ok(s)) {
		ans = s;
		return;
	}
	for(int i = 0; i < 10; ++i) {
		
	}
}*/

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int T,n;
	cin >> T;
	while(T--) {
		cin >> n;
		for(int i = 0; i < n; ++i) cout << n;
		cout << endl;
	}
    return 0;
}
