/*************************************************************************
    > File Name: cf580A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年08月14日 星期三 13时59分17秒
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


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n, ans = 0,x = 0;
	cin >> n;
	vector<int> v;
	for(int i = 1; i <= n; ++i) {
		cin >> x;
		if(v.size() == 0 || x >= v[v.size() - 1]) {
			v.push_back(x);
			ans = max(ans,(int)v.size());
		}else{
			v.clear();
			v.push_back(x);
		}
	}
	cout << ans << endl;
    return 0;
}
