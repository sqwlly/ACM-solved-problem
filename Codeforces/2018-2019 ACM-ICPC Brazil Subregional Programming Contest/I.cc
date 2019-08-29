/*************************************************************************
    > File Name: I.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年08月29日 星期四 09时39分23秒
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
int light[N], cnt[N], sum[N][N];
pair<int,vector<int>> swt[N];
vector<int> init;
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,m,k,x;
	cin >> n >> m >> k;
	for(int i = 0; i < k; ++i) {
		cin >> x;
		light[x] = 1;
		init.push_back(x);
	}
	for(int i = 0; i < n; ++i) {
		cin >> k;
		for(int j = 0; j < k; ++j) {
			cin >> x;
			swt[i].second.push_back(x);
			cnt[x]++;
			sum[i + 1][x] = sum[i][x] + 1;
		}
	}

	for(int i = 1; i <= n; ++i) {
		bool ok = 1;
	}
	for(int i = 1; i <= m; ++i) {
		if(cnt[i] & 1) {
			light[i] ^= 1;
		}
	}
    return 0;
}
