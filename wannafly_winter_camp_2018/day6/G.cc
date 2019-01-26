/*************************************************************************
    > File Name: G.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年01月26日 星期六 13时54分35秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
vector<int> v[101];
int f[101];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n,m,x;
	cin >> n >> m;
	for(int i = 0; i < m; ++i) {
		int k;
		cin >> k;
		for(int j = 0; j < k; ++j) {
			cin >> x;
			v[i].push_back(x);
		}
	}
	int pre = 1;
	bool vis[101] = {0};
	vector<int> ans;
	for(int id = 1; id <= n; ++id) {
		memset(vis,0,sizeof vis);
		vis[id] = 1;
		for(int i = 0; i < m; ++i) {
			for(int j = 0; j < v[i].size(); ++j) {
				if(v[i][j] == id || vis[v[i][j]]) {
					for(int k = j; k >= 0; --k) {
						vis[v[i][k]] = 1;
					}
				}
			}
		}
		int cnt = 0;
		for(int i1 = 1; i1 < 101; ++i1) {
			if(vis[i1] == 1) {
	//			cnt++;
				for(int i = 0; i < m; ++i) {
					for(int j = 0; j < v[i].size(); ++j) {
						if(v[i][j] == i1 || vis[v[i][j]]) {
							for(int k = j; k >= 0; --k) {
								vis[v[i][k]] = 1;
							}
						}
					}
				}
			}
		}
		for(int i = 1; i < 101; ++i) {
			if(vis[i]) 
				cnt++;
		}
		ans.push_back(cnt);
		if(cnt < pre) {
			pre = cnt;
			vis[id] = 0;
		}
	}
	cout<<*min_element(ans.begin(),ans.end())<<endl;
    return 0;
}
