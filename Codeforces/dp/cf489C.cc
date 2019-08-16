/*************************************************************************
    > File Name: cf489C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年08月15日 星期四 10时53分11秒
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
const int N = 1000;
int g[N][2];

bool can(int m,int s)
{
	return (m * 9 >= s && s >= 0);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int m,s,t;
	cin >> m >> s;
	t = s;
	string a = "",b = "";
	for(int i = 1; i <= m; ++i) {
		for(int k = 0; k < 10; ++k) {
			if(can(m - i, s - k)) {
				if(i == 1 && k == 0 && m > 1) continue;
				a += to_string(k);
				s -= k;
				break;
			}
		}
	}
	s = t;
	for(int i = 1; i <= m; ++i) {
		for(int k = 9; k >= 0; --k) {
			if(can(m - i, s - k)) {
				b += to_string(k);
				s -= k;
				break;
			}
		}
	}
	if(a.length() != m || b.length() != m) a = "-1", b = "-1"; 
	cout << a << ' ' << b << endl;
    return 0;
}
