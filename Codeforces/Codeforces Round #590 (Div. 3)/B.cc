/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年10月01日 星期二 22时51分25秒
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

int a[300], front, rear;
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
			vis[a[k - 1]] = 0;
			for(int j = k; j >= 1; --j) {
				a[j] = a[j - 1];
			}
			a[0] = x;
			vis[x] = 1;
		}
	}
	int cnt = 0;
	for(int i = 0; a[i]; ++i) {
		cnt++;
	}
	cnt = min(cnt, k);
	cout << cnt << endl;
	for(int i = 0; i < cnt; ++i) 
		cout << a[i] << (i == cnt - 1 ? '\n' :' ');
    return 0;
}