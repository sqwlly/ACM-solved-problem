/*************************************************************************
    > File Name: B2.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2020年01月14日 星期二 16时01分51秒
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
	//cbc
	//baa
	//cbb
	//caa
	//cab
	//cab
	//
	//abc
	//bca
	//
	//aba
	//bcc
	//
	//abb
	//acc
	//
	//abc
	//abc
	int k;
	cin >> k;
	while(k--) {
		int n;
		string s,t;
		cin >> n >> s >> t;
		map<int,int> cnt;
		for(auto i : s) {
			cnt[i]++;
		}
		for(auto i : t) {
			cnt[i]++;
		}
		bool ok = 1;
		for(auto i : cnt) {
			if(i.second & 1) {
				ok = 0;
				break;
			}
		}
		if(!ok) {
			cout << "No\n";
			continue;
		}
		cout << "Yes\n";
		vector<pair<int,int>> v;
		for(int i = 0; i < n; ++i) {
			if(s[i] == t[i]) continue;
			for(int j = i + 1; j < n; ++j) {
				if(s[i] == s[j]) {
					v.push_back(make_pair(j,i)); //注意j和i不要写反
					swap(s[j],t[i]);
					break;
				}else if(s[i] == t[j]) {
					v.push_back(make_pair(j,j));
					swap(s[j],t[j]);
					v.push_back(make_pair(j,i));
					swap(s[j],t[i]);
					break;
				}
			}
		}
		cout << v.size() << '\n';
		for(auto i : v) {
			cout << i.first + 1 << ' ' << i.second + 1 << '\n';
		}
	}
    return 0;
}
