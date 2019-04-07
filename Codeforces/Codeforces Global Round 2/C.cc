/*************************************************************************
    > File Name: C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年04月06日 星期六 21时05分13秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 512;
int a[N][N],b[N][N];

void doit(int i,int j)
{
	if(a[i][j] == b[i][j]) return;
	a[i][j] ^= 1;
	a[i + 1][j] ^= 1;
	a[i][j + 1] ^= 1;
	a[i + 1][j + 1] ^= 1; 
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			cin >> a[i][j];
		}
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			cin >> b[i][j];
		}
	}
	for(int i = 0; i < n - 1; ++i) {
		for(int j = 0; j < m - 1; ++j) {
			doit(i,j);
		}
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			if(a[i][j] != b[i][j]) return cout << "No" << endl,0;
		}
	}
	cout << "Yes" << endl;
    return 0;
}
