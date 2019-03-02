/*************************************************************************
    > File Name: D.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月02日 星期六 11时53分22秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
int dis[1 << 21];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,m;
	memset(dis, -1, sizeof dis);
	string s;
	cin >> n >> m;
	queue<int> q;
	for(int i = 0; i < n; ++i) {
		cin >> s;
		int t = 0;
		for(int j = 0; j < m; ++j) {
			t |= (1 << j) * (s[j] == '1');
		}
		if(dis[t] == -1) {
			dis[t] = 0;
			q.push(t);
		}
	}
	int ans = 0;
	while(!q.empty()) {
		int cur = q.front(); q.pop();
		ans = max(ans, dis[cur]);
		for(int i = 0; i < m; ++i) {
			if(dis[cur ^ (1 << i)] == -1) {
				dis[cur ^ (1 << i)] = dis[cur] + 1;
				q.push(cur ^ (1 << i));
			}
		}
	}
	cout << m - ans << endl;
    return 0;
}
