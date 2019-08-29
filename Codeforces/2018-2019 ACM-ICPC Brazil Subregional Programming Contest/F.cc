/*************************************************************************
    > File Name: F.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年08月29日 星期四 12时30分35秒
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
const int N = 1024;
struct node{
	int l,r,w,id;
	bool operator < (const node &u) const{
		if(w == u.w) {
			if(r == u.r) return l < u.l;
			return r < u.r;
		}else{
			return w > u.w;
		}
	}
};

vector<node> v[20],g;
int dp[20][N];
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,k,l,r,w;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> k;
		for(int j = 0; j < k; ++j) {
			cin >> l >> r >> w;
			v[i].push_back(node{l,r,w,i});
			g.push_back(node{l,r,w,i});
		}
		sort(v[i].begin(), v[i].end());
	}
	sort(g.begin(), g.end());
	for(int i = 0; i < n; ++i) {
		for(auto j : v[i]){
			bool ok = 0;
			for(int k = 0; k < n; ++k) {
				if(i != k) {
					for(auto c : v[k]) {
						if(max(j.l,c.l) >= min(j.r,c.r)) {
							ok = 0;
						}
					}
				}
			}
		}

		for(int j = 0; j < n; ++j) {
			if(i != j) {
				for(int k = 0; k < v[j].size(); ++k)
			}
		}
	}
	for(int i = 0; i < g.size(); ++i) {
		for(int j = 0; j <)
	}
	
	long long ans = 0;
	for(int cnt = 0; cnt < 1001; ++cnt) {
		int last = 0;
		for(int i = 0; i < n; ++i) {
			for(auto j : v[i]) {
				if(j.l > last)
			}
		}
	}
    return 0;
}
