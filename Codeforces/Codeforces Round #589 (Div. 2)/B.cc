/*************************************************************************
  > File Name: B.cc
  > Author: sqwlly
  > Mail: sqw.lucky@gmail.com 
  > Created Time: 2019年09月29日 星期日 22时08分32秒
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
typedef long long LL;
const int mod = 1e9+7;
int h,w,r[1 << 10], c[1 << 10], a[1 << 10][1 << 10];

void solve()
{
	memset(a, -1, sizeof a);
	for(int i = 0; i < h; ++i) {
		if(r[i] == 0) a[i][0] = 0;
	}
	for(int i = 0; i < w; ++i) {
		if(c[i] == 0) a[0][i] = 0;
	}
	for(int i = 0; i < h; ++i) {
		for(int j = 0; j < r[i]; ++j) {
			if(a[i][j] != 0) {
				a[i][j] = 1;
			}else{
				cout << 0 << '\n';
				return;
			}
		}
		a[i][r[i]] = 0;
		for(int j = r[i]; r[i] && j < w; ++j) {
			if(a[i][j] == -1 && c[j] == i) {
				a[i][j] = 0;
			}
		}
	}
	for(int j = 0; j < w; ++j) {
		for(int k = 0; k < c[j]; ++k) {
			if(a[k][j] != 0) {
				a[k][j] = 1;
			}else{
				cout << 0 << '\n';
				return;
			}
		}
		if(a[c[j]][j] != 1) {
			a[c[j]][j] = 0;
		}else{
			cout << 0 << '\n';
			return;
		}
		for(int k = c[j] - 1; c[j] && k < h; ++k) {
			if(a[k][j] == -1 && r[k] == j) {
				a[k][j] = 0;
			}
		}
	}
	LL ans = 1;
	for(int i = 0; i < h; ++i) 
		for(int j = 0; j < w; ++j) if(a[i][j] == -1) ans = ans * 2 % mod;
	cout << ans << '\n';
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> h >> w;
	for(int i = 0; i < h; ++i) cin >> r[i];
	for(int i = 0; i < w; ++i) cin >> c[i];
	solve();
	return 0;
}
