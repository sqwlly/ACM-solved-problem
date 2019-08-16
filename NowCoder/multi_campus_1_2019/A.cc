/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年07月18日 星期四 12时30分28秒
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
int dp[N],a[N],b[N],mAidx[N],mBidx[N];
#define P pair<int,int>
stack<int> stA,stB;
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n;
	while(cin >> n) {
		while(!stB.empty()) {
			stB.pop();
		}
		while(!stA.empty()) {
			stA.pop();
		}
		P mIdxA = P(0,INT_MAX);
		for(int i = 1; i <= n; ++i) cin >> a[i];
		for(int i = 1; i <= n; ++i) cin >> b[i];
		int MA = INT_MAX, MB = INT_MAX;
		memset(mAidx, 0, sizeof mAidx);
		memset(mBidx, 0, sizeof mBidx);
		int ans = 0;
		stA.push(0);
		stB.push(0);
		for(int i = 1; i <= n; ++i) {
			while(!stA.empty() && a[stA.top()] > a[i]) {
				stA.pop();
			}
			stA.push(i);
			while(!stB.empty() && b[stB.top()] > b[i]) {
				stB.pop();
			}
			stB.push(i);
			if(stA.size() != stB.size()) {
				ans = i;
				break;
			}
		}
		if(ans)
			cout << ans - 1 << endl;
		else
			cout << n << endl;
	}
    return 0;
}
