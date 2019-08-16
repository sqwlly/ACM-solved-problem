/*************************************************************************
    > File Name: cf489B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年08月16日 星期五 11时14分35秒
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
	int n,m;
	cin >> n;
	int a[101] = {0}, b[101] = {0};
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a, a + n);
	cin >> m;
	for(int i = 0; i < m; ++i) {
		cin >> b[i];
	}
	sort(b, b + m);
	int cnt = 0;
	//1 2 4 6
	//1 5 5 7 9
	//
	//2 1
	for(int i = 0, j = 0; i < n && j < m;) {
		if(abs(a[i] - b[j]) <= 1) {
			i++,j++;
			cnt++;
		}else {
			i++;
		}
	}
	cout << cnt << endl;
    return 0;
}
