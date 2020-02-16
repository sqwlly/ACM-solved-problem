/*************************************************************************
    > File Name: D.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年11月16日 星期六 10时35分10秒
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

struct Hero{
	int p,s;
	bool operator < (const Hero &u) const{
		if(u.p == p) return u.s > s;
		return u.p > p;
	}
	Hero(int x,int y) { p = x, s = y; }
};


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int T,n,m;
	cin >> T;
	while(T--) {
		cin >> n;
		vector<int> monsters;
		vector<Hero> heros;
		for(int i = 0, x; i < n; ++i) {
			cin >> x;
			monsters.push_back(x);
		}
		cin >> m;
		for(int i = 0, p, s; i < m; ++i) {
			cin >> p >> s;
			heros.push_back({p,s});
		}
		sort(heros.begin(), heros.end(), [](const Hero &u, const Hero &v)
			->int { if(u.p == v.p) return u.s > v.s; return u.p > v.p; });
		reverse(heros.begin(), heros.end());
		int days = 0;
		for(int i = 0; i < monsters.size(); ) {
			auto it = lower_bound(heros.begin(), heros.end(), Hero(monsters[i],0));
			if(it == heros.end()) {
				days = -1;
				break;
			}
			dbg(i,monsters[i],(*it).p, (*it).s);
			int cnt = (*it).s;
			while((*it).p >= monsters[i] && cnt) {
				i++;
				cnt--;
			}
			days++;
			if(i >= n) break;
		}
		cout << days << '\n';
	}
    return 0;
}
