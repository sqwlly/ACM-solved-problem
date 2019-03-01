/*************************************************************************
    > File Name: C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月01日 星期五 19时02分02秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 1E5+10;
typedef long long LL;
int f[N],node[N];
LL a[N], sum[N];
vector<int> E[N];

int getf(int v)
{
	if(f[v] == v) return v;
	return f[v] = getf(f[v]);
}

void mrg(int u,int v)
{
	int p = getf(u);
	int q = getf(v);
	if(p != q) {
		f[p] = q;
	}
}
vector<LL> value;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		f[i] = i;
	}
	int v;
	for(int i = 1; i <= n; ++i) {
		cin >> v;
		mrg(i,v);
	}
	
	for(int i = 1; i <= n; ++i) {
		E[getf(i)].push_back(a[i]);
	}
	LL ans = 0;
	for(int i = 1; i <= n; ++i) {
		if(f[i] == i) {
			LL SUM = 0;
			for(auto w : E[i]) {
				SUM += w;
			}
			value.push_back(SUM);
		}
	}
	sort(value.begin(),value.end(),greater<LL>());
	for(int i = 0; i < m && i < value.size(); ++i) {
		ans += value[i];
	}
	cout << ans << endl;
    return 0;
}
