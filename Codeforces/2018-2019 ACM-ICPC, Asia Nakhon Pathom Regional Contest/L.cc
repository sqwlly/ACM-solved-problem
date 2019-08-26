/*************************************************************************
    > File Name: L.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年08月25日 星期日 10时20分34秒
 ************************************************************************/
#include<bits/stdc++.h>

using namespace std;
const int N = 1011;
int n,m,square,rectangle;
int a[N][N], Left[N][N][3], Right[N][N][3], h[N][N][3], sum[N][N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int T;
	cin >> T;
	while(T--) {
	cin>>n>>m;
	memset(Left,0,sizeof Left);
	memset(Right,0,sizeof Right);
	memset(sum,0,sizeof sum);
	memset(h,0,sizeof h);
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			cin>>a[i][j];
			Left[i][j][0] = Right[i][j][0] = j;
			Left[i][j][1] = Right[i][j][1] = j;
			h[i][j][0] = h[i][j][1] =  1;
		}
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - a[i][j];
		}
	}
	for(int i = 1; i <= n; ++i)
		for(int j = 2; j <= m; ++j) {
			if(a[i][j] == a[i][j - 1] && a[i][j] == 0) {
				Left[i][j][0] = Left[i][j - 1][0];
				Left[i][j][1] = Left[i][j - 1][1];
			}else if(a[i][j] == a[i][j - 1] ^ 1 && Left[i][j - 1][2] < 1) {
				Left[i][j][1] = Left[i][j - 1][1];
				Left[i][j][2] = Left[i][j - 1][2] + 1;
			}
		}
    for(int i = 1; i <= n; ++i)
		for(int j = m - 1; j >= 1; --j) {
			if(a[i][j] == a[i][j + 1] && a[i][j] == 0) { 
				Right[i][j][0] = Right[i][j + 1][0];
				Right[i][j][1] = Right[i][j + 1][1];
			}else if(a[i][j] == a[i][j + 1] ^ 1 && Right[i][j + 1][2] < 1) {
				Right[i][j][1] = Right[i][j + 1][1];
				Right[i][j][2] = Right[i][j + 1][2] + 1;
			}
		}
	for(int i = 1; i <= m; ++i)  {
		Left[0][i][0] = 0, Right[0][i][0] = m + 1;
		Left[0][i][1] = 0, Right[0][i][1] = m + 1;
	}
	for(int i = 1; i <= n; ++i) 
		for(int j = 1; j <= m; ++j){
			if(a[i][j] == a[i - 1][j] && i != 1 && a[i][j] == 0){
				h[i][j][0] += h[i - 1][j][0];
				h[i][j][1] += h[i - 1][j][1];
				Left[i][j][0] = max(Left[i][j][0],Left[i - 1][j][0]);
				Right[i][j][0] = min(Right[i][j][0],Right[i - 1][j][0]);
				Left[i][j][1] = max(Left[i][j][1],Left[i - 1][j][1]);
				Right[i][j][1] = min(Right[i][j][1],Right[i - 1][j][1]);
			}else if(a[i][j] == a[i - 1][j] ^ 1 && h[i - 1][j][2] < 1 && i != 1){
				h[i][j][1] += h[i - 1][j][1];
				h[i][j][2] = h[i - 1][j][2] + 1;
				Left[i][j][1] = max(Left[i][j][1],Left[i - 1][j][1]);
				Right[i][j][1] = min(Right[i][j][1],Right[i - 1][j][1]);
			}
			int w0 = Right[i][j][0] - Left[i][j][0] + 1;
			int w1 = Right[i][j][0] - Left[i][j][1] + 1;
			int w2 = Right[i][j][1] - Left[i][j][0] + 1;
			int h1 = h[i][j][1];
			int h2 = h[i][j][0];
				
			int t[4] = {0};
			t[0] = min(w0,h2), t[1] = min(w0,h1), t[2] = min(w1,h2), t[3] = min(w2,h2);
			for(int k = 0; k < 4; ++k) {
				square = max(square, t[k]);
			}
		}
		cout<<square<<'\n';
	}
	return 0;
}

//
//4 5
//1 1 1 1 1
//0 1 0 0 0
//0 0 0 0 1
//1 0 0 0 1

