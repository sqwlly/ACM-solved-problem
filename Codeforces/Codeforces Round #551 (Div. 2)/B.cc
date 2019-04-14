/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年04月13日 星期六 22时26分29秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 200;
int f_view[N], l_view[N], t_view[N][N], a[N][N];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,m,h;
	cin >> n >> m >> h;
	for(int i = 0; i < m; ++i) {
		cin >> f_view[i];
	}
	for(int i = 0; i < n; ++i) {
		cin >> l_view[i];
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			cin >> t_view[i][j];
		}
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			if(l_view[i] && t_view[i][j]) {
			//	if(i == 2 && (j == 0 || j == 1)) {
			//		DEBUG(f_view[i])
			//	}
				a[i][j] = min(f_view[j],l_view[i]);
			}
		}
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			cout << a[i][j] << (j == m - 1 ? '\n' : ' ');
		}
	}
    return 0;
}
