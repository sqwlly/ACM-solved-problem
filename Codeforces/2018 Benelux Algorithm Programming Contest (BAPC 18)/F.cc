/*************************************************************************
    > File Name: F.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年08月28日 星期三 10时00分02秒
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
int n,M;
pair<int,int> p[N];



bool check(long long x)
{
	long long cst = 0;
	for(int i = 0; i < n; ++i) {
		cst += p[i].first * x - p[i].second;
		if(cst >= M) return 1;
	}
	return 0;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> M;
	for(int i = 0; i < n; ++i) {
		cin >> p[i].first >> p[i].second;
	}
	sort(p, p + n,[](const pair<int,int> &u,const pair<int,int> &v)->int{ return u.second / u.first < v.second / v.first;});
	long long l = 1, r = INT_MAX, ans = 0;
	while(l <= r) {
		long long mid = l + r >> 1;
		if(check(mid)) {
			ans = mid;
			r = mid - 1;
		}else{
			l = mid + 1;
		}
	}
	cout << ans << endl;
    return 0;
}
