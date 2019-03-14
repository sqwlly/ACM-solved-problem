/*************************************************************************
    > File Name: 7-10.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月13日 星期三 20时01分05秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 1024;
int f[N], fa[N];

int getf(int v)
{
	if(f[v] == v) return v;
	return f[v] = getf(f[v]);
}

void mrge(int u,int v)
{
	int p = getf(u);
	int q = getf(v);
	if(p != q) f[p] = q;
}
vector<vector<int>> v;
int cnt[N];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n, x;
	string s;
	cin >> n;
	for(int i = 0; i <= n; ++i) f[i] = i;
	for(int i = 1; i <= n; ++i) {
		cin >> s;
		int k = s[0] - '0';
		vector<int> t;
		for(int j = 0; j < k; ++j) {
			cin >> x;
			if(fa[x] == 0) {
				fa[x] = i;
			}else{
				mrge(i, fa[x]);
			}
			t.push_back(x);
		}
		v.push_back(t);
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 0; j < v[i - 1].size(); ++j) {
//			mrge(i, fa[v[i - 1][j]]);
		}
	}
	int k = 0;
	vector<int> ans;
	for(int i = 1; i <= n; ++i) {
		if(f[i] == i) {
			k++;
		}
		cnt[getf(i)]++;
	}
	for(int i = 1; i <= n; ++i) {
		if(f[i] == i) ans.push_back(cnt[i]);
	}
	cout << k << endl;
	sort(ans.begin(),ans.end(),greater<int>());
	for(int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << (i == ans.size() - 1 ? '\n' : ' ');
	}
    return 0;
}
