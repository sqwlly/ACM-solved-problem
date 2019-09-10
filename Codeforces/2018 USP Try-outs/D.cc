/*************************************************************************
  > File Name: D.cc
  > Author: sqwlly
  > Mail: sqw.lucky@gmail.com 
  > Created Time: 2019年09月03日 星期二 11时22分08秒
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
struct node{
	int x,y;
	char id;
};
const int N = 1E6+10;
node p[N];
int pre[N][2],suf[N][2];
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> p[i].x >> p[i].y >> p[i].id;
	}
	p[0] = {INT_MAX,INT_MAX,'b'};
	sort(p + 1, p + n + 1,[](const node &u,const node &v)->int{if(u.x == v.x) return u.y < v.y; return u.x < v.x;});

	for(int i = 1; i <= n; ++i) {
		pre[i][0] = pre[i - 1][0] + (p[i].id == 'w');
		pre[i][1] = pre[i - 1][1] + (p[i].id == 'b');
	}
	for(int i = n; i >= 1; --i) {
		suf[i][0] = suf[i + 1][0] + (p[i].id == 'w');
		suf[i][1] = suf[i + 1][1] + (p[i].id == 'b');
	}
	int ans = 0;
//	for(int i = 1; i <= n; ++i) dbg(p[i].x,p[i].y,p[i].id);
	for(int i = 1; i <= n; ++i) {
	//	dbg(i,pre[i][0],suf[i][1],pre[i][1],suf[i][0]);
		if(p[i].x == p[i - 1].x) continue;
	//	dbg(i,pre[i - 1][0],suf[i][1],pre[i - 1][1],suf[i][0]);
		ans = max(ans, pre[i - 1][0] + suf[i][1]);
		ans = max(ans, pre[i - 1][1] + suf[i][0]);
	}	
	sort(p + 1, p + n + 1,[](const node &u,const node &v)->int{if(u.y == v.y) return u.x < v.x; return u.y < v.y;});
	for(int i = 1; i <= n; ++i) {
		pre[i][0] = pre[i - 1][0] + (p[i].id == 'w');
		pre[i][1] = pre[i - 1][1] + (p[i].id == 'b');
	}
	for(int i = n; i >= 1; --i) {
		suf[i][0] = suf[i + 1][0] + (p[i].id == 'w');
		suf[i][1] = suf[i + 1][1] + (p[i].id == 'b');
	}
	for(int i = 1; i <= n; ++i) {
		if(p[i].y == p[i - 1].y) continue;
		ans = max(ans, pre[i - 1][0] + suf[i][1]);
		ans = max(ans, pre[i - 1][1] + suf[i][0]);
	}	
	cout << ans << '\n';
	return 0;
}
