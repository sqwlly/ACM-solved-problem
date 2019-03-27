/*************************************************************************
    > File Name: C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月27日 星期三 23时57分59秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 1024;
int a[N][N],X[N][N],Y[N][N],r[N],c1[N],c2[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			cin >> a[i][j];
		}
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			r[j] = a[i][j];
		}
		sort(r + 1, r + 1 + m);
		c1[i] = unique(r + 1, r + 1 + m) - r - 1;
		for(int j = 1; j <= m; ++j) {
			X[i][j] = lower_bound(r + 1, r + c1[i] + 1, a[i][j]) - r;
		}
	}
	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j <= n; ++j) {
			r[j] = a[j][i];
		}
		sort(r + 1, r + 1 + n);
		c2[i] = unique(r + 1, r + 1 + n) - r - 1;
		for(int j = 1; j <= n; ++j) {
			Y[j][i] = lower_bound(r + 1, r + c2[i] + 1, a[j][i]) - r;
		}
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			cout << max(X[i][j], Y[i][j]) + max(c1[i] - X[i][j], c2[j] - Y[i][j]) << ' ';
		}
		cout << endl;
	}
    return 0;
}
