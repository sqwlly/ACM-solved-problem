/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年09月15日 星期日 19时00分37秒
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
const int N = 2E5+10;
int dp[N][2], a[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		if(a[i] < 0) {
			a[i] = 1;
		}else{
			a[i] = 2;
		}
	}
	long long sum1 = 0, sum2 = 0;
	for(int i = 1; i <= n; ++i) {
		if(a[i] & 1) {
			dp[i][1] += dp[i - 1][0] + 1;
			dp[i][0] += dp[i - 1][1];
		}else{
			dp[i][0] += dp[i - 1][0] + 1;
			dp[i][1] += dp[i - 1][1];
		}
		sum1 += dp[i][1];
		sum2 += dp[i][0];
	}
	cout << sum1 << ' ' << sum2 << '\n';
    return 0;
}
