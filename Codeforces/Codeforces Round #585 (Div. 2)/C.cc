/*************************************************************************
    > File Name: C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年09月15日 星期日 19时45分02秒
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
	int n;
	string s,t;
	cin >> n >> s >> t;
	int a = 0, b = 0;
	vector<int> v,p,q;
	vector<pair<int,int>> ret;
	for(int i = 0; i < s.size(); ++i) {
		if(s[i] == 'a') {
			a++;
		}else{
			b++;
		}
		if(t[i] == 'a') {
			a++;
		}else{
			b++;
		}
		int x = s[i] - 'a';
		int y = t[i] - 'a';
		if(x == 0 && y == 1) {
			p.push_back(i + 1);
		}else if(x == 1 && y == 0) {
			q.push_back(i + 1);
		}
	}

	if((a & 1) || (b & 1)) {
		return cout << -1 << '\n',0;
	}
	for(int i = 0; i < p.size() && i + 1 < p.size(); i += 2) {
		ret.push_back(make_pair(p[i], p[i + 1]));
	}
	if(p.size() & 1) {
		q.push_back(p[p.size() - 1]);
		ret.push_back(make_pair(p[p.size() - 1],p[p.size() - 1]));
	}
	for(int i = 0; i < q.size(); i += 2) {
		ret.push_back(make_pair(q[i], q[i + 1]));
	}
	cout << ret.size() << endl;
	for(int i = 0; i < ret.size(); ++i) {
		cout << ret[i].first << ' ' << ret[i].second << '\n';
	}
    return 0;
}
