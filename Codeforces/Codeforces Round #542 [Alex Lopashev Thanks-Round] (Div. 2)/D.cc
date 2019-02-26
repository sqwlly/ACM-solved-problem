/*************************************************************************
    > File Name: D.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年02月25日 星期一 13时17分51秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
vector<int> v[5050];
int n,m;
int dis(int a,int b)
{
	if(b >= a) return b - a;
	else return n - (a - b);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int a,b;
	cin >> n >> m;
	for(int i = 0; i < m; ++i) {
		cin >> a >> b;
		v[a].push_back(dis(a,b));
	}
	for(auto &i : v) sort(i.begin(),i.end());
	int ans = -1;
	for(int i = 1; i <= n; ++i) {
		ans = -1;
		for(int j = 1; j <= n; ++j) {
			if(v[j].size()) {
				int t = (v[j].size() - 1) * n + dis(i,j) + v[j][0];
				ans = max(ans,t);
			}
		}
		cout << ans << ' ';
	}
    return 0;
}
