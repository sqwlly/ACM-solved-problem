/*************************************************************************
    > File Name: C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年04月13日 星期六 19时51分59秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 1E4+10, M = 1024;
int student[N];
vector<int> school[M];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int T,n,m,k;
	cin >> T;
	while(T--) {
		for(int i = 0; i < M; ++i) school[i].clear();
		cin >> n >> m >> k;
		for(int i = 1; i <= n; ++i) {
			cin >> student[i];
			school[student[i]].push_back(i);
		}
		int cnt = 0;
		for(int i = 1; i <= m; ++i) {
			int x = school[i].size();
			sort(school[i].begin(), school[i].end());
			for(int j = 0; j < x / k; ++j) {
				if(school[i][j] <= n / 2) {
					cnt++;
				}
			}
		}
		cout << cnt << endl;
	}
    return 0;
}
