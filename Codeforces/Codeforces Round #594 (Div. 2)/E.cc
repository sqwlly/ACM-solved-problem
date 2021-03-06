/*************************************************************************
    > File Name: E.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年10月31日 星期四 22时12分50秒
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
constexpr int N = 1E5+10;
int ret[N];
struct node{
	int t,ic;
	bool operator < (const node &u) const{
		if(t == u.t) return ic < u.ic;
		return t < u.t;
	}
}a[N];
priority_queue<int,vector<int>,greater<int>> pq;
queue<int> q;
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,p;
	cin >> n >> p;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i].t;
		a[i].ic = i;
	}
	long long T = 0;
	int last = N;
	sort(a + 1, a + n + 1);
	for(int i = 1; i <= n;) {
		if(!q.empty()) {
			int cur = q.front();
			q.pop();
			ret[cur] = T + p;
			T += p;
			last = cur;
		}else if(T >= a[i].t){
			if(q.empty() && a[i].ic < last) {
				q.push(a[i].ic);
			}else if(!q.empty() && q.back() > a[i].ic && a[i].ic < last){
				q.push(a[i].ic);
			}else{
				pq.push(a[i].ic);
			}
			i++;
		}else{
			if(!pq.empty()) {
				int cur = pq.top();
				pq.pop();
				ret[cur] = T + p;
				T += p;
				last = cur;
			}else{
				T = a[i].t;
				last = N + 1;
			}

		}
	}
	while(!q.empty()) {
		int cur = q.front(); q.pop();
		ret[cur] = (T += p);
	}
	while(!pq.empty()) {
		int cur = pq.top(); pq.pop();
		ret[cur] = (T += p);
	}
	for(int i = 1; i <= n; ++i) {
		cout << ret[i] << " \n"[i == n];
	}
    return 0;
}
