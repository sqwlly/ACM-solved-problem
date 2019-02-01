/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年01月31日 星期四 20时38分03秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
string s[505];
int n;

int count1(int x,int y)
{
	if(s[x][y] != 'X') return 0;
	int dir[4][2] = {-1,-1,-1,1,1,-1,1,1};
	for(int i = 0; i < 4; ++i) {
		int tx = x + dir[i][0];
		int ty = y + dir[i][1];
		if(tx < 0 || tx >= n || ty < 0 || ty >= n)
			return 0;
		if(s[tx][ty] != 'X') return 0;
	}
	return 1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	int ans = 0;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			ans += count1(i,j);
		}
	}
	cout << ans << endl;
    return 0;
}
