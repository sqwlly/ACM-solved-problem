/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年09月11日 星期三 11时18分39秒
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
int n;
#define P pair<int,int>
vector<P> p,k;
map<P,int> cnt;
int dfs(int cur)
{
	
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	int x,y;
	for(int i = 0; i < n; ++i) {
		cin >> x >> y;
		p.push_back(make_pair(x,y));
	}
	for(int i = 0; i < n; ++i) {
		for(int j = i + 1; j < n; ++j) {
			y = p[i].second - p[j].second;
			x = p[i].first - p[j].first;
			int g = __gcd(y, x);
			k.push_back(make_pair(y / g, x / g));
			cnt[P(y / g, x / g)]++;
		}
	}
	vector<P> t;
	for(auto i : cnt) {
		if(i.second > 1) {
			t.push_back(i.first);
		}
	}
	dbg(t.size());
    return 0;
}
