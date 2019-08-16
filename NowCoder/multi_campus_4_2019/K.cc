/*************************************************************************
    > File Name: K.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年07月27日 星期六 12时11分38秒
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
const int N = 1E6+10;
string s;
int sum [N];
map<int,int> cnt;
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	cin >> s;
	int n = s.length();
    long long ans = 0;
	for(int i = 0; i < n; ++i) {
		sum[i + 1] = (sum[i] + s[i]) % 3;
	}
	for(int i = 0; i < n; ++i) {
		if(s[i] == '0') {
			ans++;
			if(i > 0 && s[i - 1] == '0') {
				ans++;
				ans += cnt[sum[i + 1]];
			}
		}
		if(i > 0) {
			cnt[sum[i - 1]]++;
		}
	}
	cout << ans << endl;
    return 0;
}

