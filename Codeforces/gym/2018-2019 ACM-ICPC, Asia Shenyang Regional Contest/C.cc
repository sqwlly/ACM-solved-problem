/*************************************************************************
    > File Name: C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年09月06日 星期五 10时00分22秒
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

int dp[100];
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int T,n,k;
	cin >> T;
	vector<int> v;
	while(T--) {
		cin >> n >> k;
		v.clear();
		for(int i = 1; i <= n; ++i) {
			v.push_back(i);
		}
		dbg(n,k);
		int cnt = 0;
		do{
			vector<int> a = v;
			sort(a.begin(),a.begin() + k);
			for(int i = 1; i <= n; ++i) dp[i] = 1;
			for(int i = 2; i <= n; ++i) {
				for(int j = 1; j < i; ++j) {
					if(a[i - 1] > a[j - 1]) {
						dp[i] = max(dp[i], dp[j] + 1);
					}
				}
			}
			if((*max_element(dp + 1, dp + n + 1)) >= n - 1) cnt++;
		}while(next_permutation(v.begin(),v.end()));
		cout << cnt << '\n';
	}
    return 0;
}
