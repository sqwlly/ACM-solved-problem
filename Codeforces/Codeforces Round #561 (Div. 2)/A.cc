/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年05月17日 星期五 23时04分59秒
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
vector<string> s[200];
vector<string> a,b;
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n;
	string x;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> x;
		s[x[0]].emplace_back(x);
	}
	for(int i = 'a'; i <= 'z'; ++i) {
		for(int j = 0; j < s[i].size();) {
			a.emplace_back(s[i][j++]);
			if(j < s[i].size())
			b.emplace_back(s[i][j++]);
		}
	}
	int cnt = 0;
	for(int i = 0; i < a.size(); ++i) {
		for(int j = i + 1; j < a.size(); ++j) {
			if(a[i][0] == a[j][0]) {
				cnt++;
			}
		}
	}
	for(int i = 0; i < b.size(); ++i) {
		for(int j = i + 1; j < b.size(); ++j) {
			if(b[i][0] == b[j][0]) {
				cnt++;
			}
		}
	}
	cout << cnt << endl;
    return 0;
}
