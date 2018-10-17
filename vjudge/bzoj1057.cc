/*************************************************************************
    > File Name: bzoj1057.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年10月15日 星期一 09时25分11秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
const int N = 2001;
int n,m,square,rectangle;
int a[N][N], Left[N][N], Right[N][N], l[N][N], r[N][N], h[N][N];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	cin>>n>>m;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			cin>>a[i][j];
			Left[i][j] = Right[i][j] = j;
			h[i][j] = 1;
		}
	}
	for(int i = 1; i <= n; ++i)
		for(int j = 2; j <= m; ++j)
			if(a[i][j] == a[i][j - 1] ^ 1) Left[i][j] = Left[i][j - 1];
    for(int i = 1; i <= n; ++i)
		for(int j = m - 1; j >= 1; --j)
			if(a[i][j] == a[i][j + 1] ^ 1) Right[i][j] = Right[i][j + 1];
	for(int i = 1; i <= m; ++i) Left[0][i] = 0, Right[0][i] = m + 1;
	for(int i = 1; i <= n; ++i) 
		for(int j = 1; j <= m; ++j){
			if(a[i][j] == a[i - 1][j] ^ 1 && i != 1){
				h[i][j] += h[i - 1][j];
				Left[i][j] = max(Left[i][j],Left[i - 1][j]);
				Right[i][j] = min(Right[i][j],Right[i - 1][j]);
			}
			int t = min(h[i][j],Right[i][j] - Left[i][j] + 1);
			square = max(square, t * t);
			rectangle = max(rectangle, h[i][j] * (Right[i][j] - Left[i][j] + 1));
		}
	cout<<square<<'\n'<<rectangle<<endl;
	return 0;
}
