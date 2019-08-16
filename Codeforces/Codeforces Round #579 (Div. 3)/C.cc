/*************************************************************************
    > File Name: C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年08月13日 星期二 22时44分06秒
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
/*******************6
 * 6 90 12 18 30 18
 * *********************************************************************************/
const int N = 4E5+10;
typedef long long LL;
map<LL,int> m;
set<int> s;
int a[N];
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		s.insert(a[i]);
	}
	//sort(a, a + n);
	long long X = *max_element(a, a + n);

	//sqrt(1e12) * log(1e12);
	for(int i = 2; 1LL * i * i <= X; ++i) {
		if(X % i == 0) {
			for(int j = i; j <= X; j += i) {
				if(s.find(j) != s.end()) {
				//	dbg(i,j);
					m[j]++;
				}
			}	
		}
	}
	int ans = INT_MAX;
	for(int i = 0; i < n; ++i) {
	//	dbg(m[a[i]]);
		if(m[a[i]] < ans && m[a[i]]) ans = m[a[i]];
	}
	if(ans == INT_MAX) ans = 0;
	cout << ans + 1 << endl;
    return 0;
}
