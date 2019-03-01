/*************************************************************************
    > File Name: D.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年02月23日 星期六 19时45分03秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define P pair<int,int>
using namespace std;
int a[2010], f[2020], in[2010], ans[2010];
vector<int> E[2010];

int getf(int v) 
{
	if(f[v] == v) return v;
	return f[v] = getf(f[v]);
}

void mrg(int u,int v)
{
	int p = getf(u);
	int q = getf(v);
	if(p != q) f[p] = q;
}

void addEdge(int u,int v)
{
	E[u].push_back(v);
	in[v]++;
}

bool topsort(int n)
{
	queue<P> q;
	for(int i = 1; i <= n; ++i) if(!in[i]) q.push(P(i,1));
	while(!q.empty()) {
		P cur = q.front(); q.pop();
		ans[cur.first] = cur.second;
		for(auto v : E[cur.first]) {
			if(--in[v] == 0) q.push(P(v,cur.second + 1));
		}
	}
	for(int i = 1; i <= n; ++i) {
		if(!(ans[i] = ans[getf(i)])) return 0;
	}
	return 1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,m;
	for(int i = 0; i < 2010; ++i) f[i] = i;
	cin >> n >> m;
	string s[1020];
	for(int i = 0; i < n; ++i)
		cin >> s[i];
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			if(s[i - 1][j - 1] == '=') mrg(i, n + j);
		}
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			if(s[i - 1][j - 1] == '>') {
				if(getf(i) != getf(n + j)) {
					addEdge(getf(n + j), getf(i));
				}else{
					return cout << "No\n",0;
				}
			}else if(s[i - 1][j - 1] == '<') {
				if(getf(i) != getf(n + j)) {
					addEdge(getf(i), getf(n + j)); 
				}else{
					return cout << "No\n",0;
				}
			}
		}
	}
	if(topsort(n + m)) {
		cout << "Yes" << endl;
		for(int i = 1; i <= n + m; ++i) {
			cout << ans[i] << (((i == n)||(i == n + m)) ? '\n' : ' ');
		}
	}else{
		cout << "No" << endl;
	}
    return 0;
}
