/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年08月27日 星期二 09时04分11秒
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

int g(string s)
{
	int ret = 0;
	for(int i = 0; i < s.length(); ++i) {
		ret = ret * 10 + s[i] - '0';
	}
	return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,ok = 1,cur = 0;
	string s;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> s;
		if(s == "mumble"){
			cur++;
		}else if(cur + 1 == g(s)) {
			cur++;
		}else{
			ok = 0;
		}
	}
	cout << (ok ? "makes sense" : "something is fishy") << endl;
    return 0;
}
