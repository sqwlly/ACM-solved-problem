/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年08月18日 星期日 11时00分26秒
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
	int q,n;
	cin >> q;
	while(q--) {
		int a[201] = {0};
		cin >> n;
		int stx = 0;
		for(int i = 0; i < n; ++i) {
			cin >> a[i];
			if(a[i] == 1) {
				stx = i;
			}
		}
		int num_1 = 2, num_2 = 2, sty = stx;;
		bool ok1 = 1, ok2 = 1;
		while(num_1 <= n) {
			if(a[(stx + 1) % n] == num_1) {
				stx = (stx + 1) % n;
				num_1++;
			}else{
				ok1 = 0;
				break;
			}
		}
		stx = sty;
		while(num_2 <= n) {
			if(a[(stx - 1 + n) % n] == num_2) {
				stx = (stx - 1 + n) % n;
				num_2++;
			}else{
				ok2 = 0;
				break;
			}
		}
		string ans = (ok1 || ok2) ? "YES" : "NO";
		cout << ans << endl;
	}
    return 0;
}
