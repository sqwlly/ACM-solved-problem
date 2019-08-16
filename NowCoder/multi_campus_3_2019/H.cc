/*************************************************************************
    > File Name: H.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年07月25日 星期四 16时59分59秒
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
/*
 *  我就是赛后小诸葛QAQ,55555555555555555
 *
 *
 * */
const int INF = 1E5;
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int T,n;
	cin >> T;
	while(T--) {
		cin >> n;
		pair<int,int> p[1025];
		int x,y;
		for(int i = 0; i < n; ++i) {
			cin >> x >> y;
			p[i] = make_pair(x,y);
		}
		sort(p, p + n, [] (const pair<int,int> &u, const pair<int,int> &r) ->int {
			return u.first == r.first ? u.second < r.second : u.first < r.first;
		});
		cout << p[n / 2 - 1].first - 1 << ' ' << p[n / 2 - 1].second + INF << ' ' << p[n / 2].first + 1 << ' ' << p[n / 2].second - INF << endl;
	}
    return 0;
}
