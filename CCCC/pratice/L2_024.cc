/*************************************************************************
    > File Name: L2_024.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月03日 星期日 09时48分01秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 10010;
int f[N * 2];

int getf(int v)
{
	if(f[v] == v) return v;
	return f[v] = getf(f[v]);
}

void mrg(int u,int v)
{
	int fu = getf(u);
	int fv = getf(v);
	if(fu != fv) {
		f[fu] = fv;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,k,x,y,q,tot = 0;
	cin >> n;
	for(int i = 1; i <= 2 * N; ++i) f[i] = i;
	for(int i = 1; i <= n; ++i) {
		cin >> k;
		for(int j = 0; j < k; ++j) {
			cin >> x;
			tot = max(tot, x);
			int fx = getf(x);
			if(fx != x) {
				mrg(fx, i + N);
			}
			mrg(x, i + N);
		}
	}
	int cnt = 0;
	for(int i = N + 1; i <= N + n; ++i) {
		if(f[i] == i) cnt++; 
	}
	cout << tot << ' ' << cnt << endl;
	cin >> q;
	while(q--) {
		cin >> x >> y;
		cout << (getf(x) == getf(y) ? "Y" : "N") << endl;
	}
    return 0;
}
