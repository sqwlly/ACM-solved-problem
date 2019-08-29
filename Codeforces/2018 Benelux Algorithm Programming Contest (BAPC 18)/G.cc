/*************************************************************************
    > File Name: G.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年08月28日 星期三 11时21分57秒
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
const int N = 1E5+10;
//ACBACCCABAAABCCABBBBAABCBBBABABCABAACBBABBABBAACBCBCA 28
int sum[N][3];
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n, ans = INT_MAX;
	string s;
	cin >> n >> s;
	//s = s + s;
	n = s.length();
	map<int,int> cnt;
	for(int i = 0; i < n; ++i) {
		cnt[s[i]]++;
	}
	string pattern = "ABC";
	do{
		int k = 0;
		sum[0][0] = sum[0][1] = sum[0][2] = 0;
		for(int i = 1; i <= n; ++i) {
			for(int j = 0; j < pattern.size(); ++j) {
				sum[i][j] = sum[i - 1][j] + (s[i - 1] == pattern[j]);
			}
		}
		for(int ix = 0; ix < n; ++ix) {
			k = 0;
			int sx = ix;
			for(int j = 0; j < pattern.size(); sx = (sx + cnt[pattern[j]]) % n, ++j) {
				int ed = sx + cnt[pattern[j]], X = 0;
				if(ed > n) {
					X = sum[ed % n][j] + sum[n][j] - sum[sx][j];
				}else{
					X = sum[ed][j] - sum[sx][j];
				}
				k += cnt[pattern[j]] - X;
			}
			ans = min(ans, k);
		}
	}while(next_permutation(pattern.begin(),pattern.end()));

	cout << ans << endl;
    return 0;
}
