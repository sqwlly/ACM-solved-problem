/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月08日 星期五 17时32分44秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
int c[5050];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n;
	string s,b;
	cin >> n >> s >> b;
	vector<int> p,q,v,r,f;
	for(int i = 0; i < s.length(); ++i) {
	
		if(s[i] == '1') {
			v.push_back(i);
		}else{
			p.push_back(i);
		}
		if(b[i] == '1') {
			r.push_back(i);
		}else{
			q.push_back(i);
		}
	}
	if(v.size() == n || r.size() == n) {
		return cout << -1 << endl,0;
	}
	sort(v.begin(),v.end());
	sort(r.begin(),r.end());
	bool vis[5050] = {0};
	vector<int> ans;
	for(int i = 0; i < v.size() && i < n / 2; ++i) {
		for(int j = 0; j < r.size(); ++j) {
			if(vis[v[i]] || vis[r[j]]) continue;
			if(v[i] != r[j]) {
				vis[v[i]] = vis[r[j]] = 1;
				ans.push_back(v[i]);
				ans.push_back(r[j]);
				if(ans.size() == n / 2) {
					for(int i = 0; i < n / 2; ++i) 
					cout << ans[i] + 1 << ' ';
					return 0;
				}
			}
		}
	}
	for(int i = 0; i < p.size() && i < n / 2; ++i) {
		for(int j = 0; j < q.size(); ++j) {
			if(vis[p[i]] || vis[q[j]]) continue;
			if(p[i] != q[j]) {
				vis[p[i]] = vis[q[j]] = 1;
				ans.push_back(p[i]);
				ans.push_back(q[j]);
				if(ans.size() == n / 2) {
					for(int i = 0; i < n / 2; ++i) 
					cout << ans[i] + 1 << ' ';
					return 0;
				}
			}
		}
	}
	cout << -1 << endl;
    return 0;
}
