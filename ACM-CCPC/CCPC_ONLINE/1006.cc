/*************************************************************************
    > File Name: 1006.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年08月23日 星期五 12时30分03秒
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
pair<int,int> p[N];
int pos[N];
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,m,x;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		cin >> x;
		pos[x] = -i;
		p[i] = make_pair(i,x);
	}
	//3 1 2 4 5
	//4 3 1 2 5
	//3 4 1 2 5
	int k = 1;
	for(int i = 1; i <= m; ++i) {
		cin >> x;
		pos[x] = k++;
	}
	sort(p + 1, p + n + 1,[](const pair<int,int> &u,const pair<int,int> &r)->int{return pos[u.second] > pos[r.second];});
	for(int i = 1; i <= n; ++i) {
		cout << p[i].second << (i == n ? ' ' :' ');
	}
	return 0;
}
