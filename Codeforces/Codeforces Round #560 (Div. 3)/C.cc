/*************************************************************************
    > File Name: C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年05月14日 星期二 23时20分57秒
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
bool vis[200100];
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int ok = 0, cnt = 0;
	vector<int> idx;
	//aaaabbaacaaabb
		for(int i = 0; i < n;) {
			if(s[i] == s[i + 1] && i + 1 < n) {
			//	idx.emplace_back(i);
				vis[i] = 1;
				cnt++;
				i++;
			}else{
				i += 2;
			}
		}
	if((n - cnt) % 2 == 1) {
		//idx.emplace_back(n - cnt - 1);
		vis[n - 1] = 1;
		cnt++;
	}
	cout << cnt << endl;
	for(int i = 0; i < n; ++i) {
		if(vis[i] == 0) cout << s[i];
	}
	return 0;
}
