/*************************************************************************
    > File Name: C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年10月01日 星期二 23时15分36秒
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
constexpr int N = 2E5+10;
string s[2];
bool vis[N][2],ok;
int n;
int cc = 0;
void d(int x,int y,int last)
{
//	dbg(last,x,y);
	if(x == 1 && y == n) {
		ok = 1;
		return;
	}
	if(x < 0 || x >= 2 || y < 0 || y >= n) return;
	if(s[x][y] == '1' || s[x][y] == '2') {
		if(last == 1) {
			return;
		}
		if(last == 4 || last == 5) return;
		d(x, y + 1, 2);
	}else{
		if(last == 1) {
			return;
		}
		if(last == 2) {
			d(x + 1, y, 4);
			d(x - 1, y, 5);
		}
		if(last == 3) {
			d(x + 1, y, 4);
		}
		if(last == 4) {
			d(x, y + 1, 6);
		}
		if(last == 5) {
			d(x, y + 1, 3);
		}
		if(last == 6) {
			d(x - 1, y, 5);
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int q;
	cin >> q;
	while(q--) {
		cin >> n >> s[0] >> s[1];
		ok = 0;
		memset(vis,0,sizeof vis);
		d(0,0,3);
		cout << (ok ? "YES" : "NO") << '\n';
	}
    return 0;
}
