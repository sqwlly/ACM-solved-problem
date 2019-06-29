/*************************************************************************
    > File Name: D.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年06月29日 星期六 12时15分12秒
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
int dir[4][2] = {1,0,0,1,0,-1,-1,0};
#define P pair<int,int>
#define pp pair<int,P>
bool vis[50][50];
int n,m,cnt, ans = INT_MAX >> 1;
string s[50];

void bfs(int sx,int sy)
{
	priority_queue<pp,vector<pp>, greater<pp> > pq;
	pq.push(pp(0,P(sx,sy)));
	vis[sx][sy] = 1;
	while(!pq.empty()) {
		pp cur = pq.top(); pq.pop();
		int x = cur.second.first;
		int y = cur.second.second;
		if(s[x][y] == 'e') {
		//	dbg(x + 1,y + 1);
			ans = min(ans, cur.first);
			cnt++;
			continue;
		}
		for(int i = 0; i < 4; ++i) {
			int tx = cur.second.first + dir[i][0];
			int ty = cur.second.second + dir[i][1];
			if(tx < 0 || tx >= n || ty < 0 || ty >= m || vis[tx][ty] || s[tx][ty] == '*') {
				continue;
			}
			vis[tx][ty] = 1;
			pq.push(pp(cur.first + 1,P(tx,ty)));
		}
	}
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	int sx = 0, sy = 0;
	for(int i = 0; i < n; ++i) cin >> s[i];
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			if(s[i][j] == 'k') {
				sx = i; sy = j;
				break;
			}
		}
	}
	bfs(sx,sy);
	if(cnt == 0) {
		cout << -1 << endl;
	}else{
		cout << cnt << ' ' << ans << endl;
	}
    return 0;
}
