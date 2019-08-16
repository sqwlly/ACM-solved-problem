/*************************************************************************
    > File Name: hdu1789.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年07月25日 星期四 16时09分26秒
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
#define P pair<int,int> 
priority_queue<int, vector<int>, greater<int> > pq;

pair<int,int> p[1024];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		int n, x;
		cin >> n;
		for(int i = 0; i < n; ++i) {
			cin >> x;
			p[i].first = x;
		}
		for(int i = 0; i < n; ++i) {
			cin >> x;
			p[i].second = x;
		}
		sort(p, p + n, [] (const pair<int,int> &u, const pair<int,int> &v) -> int {	
			return u.first == v.first ? u.second > v.second : u.first < v.first;
		});
		while(!pq.empty()) pq.pop();
		int curTime = 0;
		long long ret = 0;
		for(int i = 0; i < n; ++i) {
			if(curTime >= p[i].first) {
				if(pq.top() < p[i].second) {
					ret += pq.top(); pq.pop(); pq.push(p[i].second);
				}else {
					ret += p[i].second;
				}
			}else{
				pq.push(p[i].second);
				curTime++;
			}
		}
		cout << ret << endl;
	}
    return 0;
}
