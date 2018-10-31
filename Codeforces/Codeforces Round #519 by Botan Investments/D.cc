/*************************************************************************
    > File Name: D.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年11月01日 星期四 00时01分34秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
const int N = 100100;
struct node{
	int nxt, cnt;
}loc[N];
int num[13][N];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n,m;
	cin>>n>>m;
	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j <= n; ++j) {
			scanf("%d",&num[i][j]);
		}
	}
	for(int i = 1; i < n; ++i) {
		loc[num[1][i]].nxt = num[1][i + 1];
		loc[num[1][i]].cnt = 1;
	}
	for(int i = 2; i <= m; ++i) {
		for(int j = 1; j < n; ++j) {
			if(loc[num[i][j]].nxt == num[i][j + 1]) loc[num[i][j]].cnt++;
		}
	}
	long long sum = 1, ans = 0;
	for(int i = 1; i < n; ++i) {
		if(loc[num[1][i]].cnt == m) sum++;
		else ans += sum * (sum + 1) / 2, sum = 1;
	}
	if(sum > 0) ans += sum * (sum + 1) / 2;
	cout<< ans << endl;
    return 0;
}
