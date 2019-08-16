/*************************************************************************
    > File Name: G.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年08月10日 星期六 12时31分29秒
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
	string s;
	cin >> s;
	stack<char> st;
	for(int i = 0; i < s.length(); ++i) {
		cout << s[i] << endl;;
		if(st.empty() || st.top() != s[i]) {
			if(!st.empty()) dbg(st.top());
			st.push(s[i]);
		}else{
			st.pop();
		}
	}
	cout << s.size() << endl;
    return 0;
}
