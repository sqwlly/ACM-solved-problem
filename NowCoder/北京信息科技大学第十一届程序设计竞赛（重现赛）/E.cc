/*************************************************************************
    > File Name: E.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年06月29日 星期六 12时33分49秒
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
const int N = 1025;
bool isPrime(int n)
{
	for(int i = 2; i * i <= n; ++i) {
		if(n % i == 0) return 0;
	}
	return n != 1;
}
vector<int> a[N];
int b[N], ans = INT_MAX,n;
bool vis[N];
set<int> s;
void dfs(int cur,int sum)
{
	if(cur == n) {
		ans = min(ans, sum);
		return;
	}
	for(int i = 0; i < a[cur].size(); ++i) {
		if(vis[a[cur][i]] == 0) {
			vis[a[cur][i]] = 1;
			dfs(cur + 1, sum + a[cur][i]);
			vis[a[cur][i]] = 0;
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> b[i];
		for(int j = 2; j <= b[i]; ++j) {
			if(b[i] % j == 0) {
				a[i].emplace_back(j);
				while(b[i] % j == 0) b[i] /= j;
				//	if(isPrime(j)) a[i].emplace_back(j);
			//	if(isPrime(b[i] / j)) a[i].emplace_back(b[i]/ j);
			}
		}
		sort(a[i].begin(),a[i].end());
	}
	dfs(0,0);
	if(ans == INT_MAX) {
		cout << -1 << endl;
	}else{
		cout << ans << endl;
	}
    return 0;
}
