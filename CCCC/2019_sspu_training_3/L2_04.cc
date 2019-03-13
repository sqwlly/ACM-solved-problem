/*************************************************************************
    > File Name: L2_04.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月12日 星期二 16时32分40秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 10010;
int f[N];

int getf(int v)
{
	if(f[v] == v) return v;
	return f[v] = getf(f[v]);
}

void merge(int u,int v)
{
	int p = getf(u);
	int q = getf(v);
	if(p != q) f[p] = q;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n, x, y, k, sum = 0;
	cin >> n;
	for(int i = 0; i < N; ++i) f[i] = i;
	for(int i = 0; i < n; ++i) {
		cin >> k >> x;
		sum = max(sum, x);
		for(int j = 1; j < k; ++j) {
			cin >> y;
			sum = max(sum, y);
			merge(y, x);
		}
	}
	int cnt = 0;
	for(int i = 1; i <= sum; ++i) {
		if(f[i] == i) {
			cnt++;
		}
	}	
	cout << sum << ' ' << cnt << endl;
	int m;
	cin >> m;
	while(m--) {
		cin >> x >> y;
		cout << (getf(x) == getf(y) ? "Y" : "N") << endl;
	}
    return 0;
}

