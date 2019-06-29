/*************************************************************************
    > File Name: C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年05月17日 星期五 23时54分23秒
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
typedef long long LL;
LL x[N];
map<LL,int> mp;
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> x[i];
		x[i] = abs(x[i]);
	}
	sort(x + 1, x + n + 1);
	long long ans = 0;
	for(int i = 1; i <= n; i++) {
		if(x[i] == x[i + 1]) {
			i++;
			ans++;
		}
		mp.insert((make_pair(-x[i],i)));
	}
	for(int i = 1; i <= n; ++i) {
		map<LL,int>::iterator it = mp.lower_bound(-2 * x[i]);
		if(it != mp.end())
		ans += (*it).second - (*mp.find(-x[i])).second;
		//dbg(x[i],(*it).first,(*it).second,ans,(*mp.find(-x[i])).second);
		//auto v = lower_bound(mp.begin((), mp.end(), );
	}
	cout << ans << endl;
    return 0;
}
