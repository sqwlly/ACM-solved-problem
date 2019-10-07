/*************************************************************************
    > File Name: B2.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年10月01日 星期二 22时59分35秒
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

deque<int> dq;

map<int,int> vis;
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,k,x;
	cin >> n >> k;
	for(int i = 0; i < n; ++i) {
		cin >> x;
		if(vis[x] == 0) {
			if(dq.size() >= k) {
				vis[dq.back()] = 0;
				dq.pop_back();
			}
			dq.push_front(x);
			vis[x] = 1;
		}
	}
	cout << dq.size() << endl;
	for(auto i : dq) {
		cout << i << ' ';
	}
	
    return 0;
}
