/*************************************************************************
    > File Name: cf489B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年08月16日 星期五 11时14分35秒
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
vector<int> E[N];
int match[N];
bool vis[N];

int dfs(int u)
{
	for(auto v : E[u]) {
		if(!vis[v]) {
			vis[v] = 1;
			if(match[v] == -1 || dfs(match[v])) {
				match[v] = u;
				return 1;
			}
		}
	}
	return 0;
}




int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,m;
	cin >> n;
	/*	匈牙利做法
	 *	
	 * */
	int a[101] = {0},b[101] = {0};
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	cin >> m;
	for(int i = 0; i < m; ++i) {
		cin >> b[i];
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			if(abs(a[i] - b[j]) <= 1) {
				E[i + 1].emplace_back(j + 1);
			}
		}
	}
	memset(match, -1, sizeof match);
	int ans = 0;
	for(int i = 1; i <= n; ++i) {
		memset(vis, 0, sizeof vis);
		ans += dfs(i);
	}
	cout << ans << endl;
	/*
	 *
	 *  暴力双指针贪心
	 *
	int a[101] = {0}, b[101] = {0};
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a, a + n);
	cin >> m;
	for(int i = 0; i < m; ++i) {
		cin >> b[i];
	}
	sort(b, b + m);
	int cnt = 0;
	//1 2 4 6
	//1 5 5 7 9
	//
	//2 1
	for(int i = 0, j = 0; i < n && j < m;) {
		if(abs(a[i] - b[j]) <= 1) {
			i++,j++;
			cnt++;
		}else if(a[i] < b[j]){
			i++;
		}else{
			j++;
		}
	}
	cout << cnt << endl;*/
    return 0;
}

