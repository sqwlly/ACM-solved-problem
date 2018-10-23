/*************************************************************************
    > File Name: P4147.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年10月23日 星期二 17时07分55秒
 ************************************************************************/

#include<bits/stdc++.h>
const int N = 1010;
using namespace std;
int n,m,rectangle,a[N][N],Left[N][N],Right[N][N],h[N][N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	char c;
	cin>>n>>m;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			cin>>c;
			a[i][j] = c == 'F' ? 1 : 0;
			Left[i][j] = Right[i][j] = j;
			h[i][j] = 1;
		}
	}
	for(int i = 1; i <= n; ++i){
		for(int j = 2; j <= m; ++j){
			if(a[i][j] == a[i][j - 1] && a[i][j] == 1) Left[i][j] = Left[i][j - 1];
		}
	}
	for(int i = 1; i <= n; ++i){
		for(int j = m - 1; j >= 1; --j){
			if(a[i][j] == a[i][j + 1] && a[i][j] == 1) Right[i][j] = Right[i][j + 1];
		}
	}
	for(int i = 1; i <= m; ++i) Left[0][i] = 0, Right[0][i] = m + 1;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j) {
			if(a[i][j] == a[i - 1][j] && i != 1 && a[i][j] == 1) {
				h[i][j] += h[i - 1][j];
				Left[i][j] = max(Left[i][j],Left[i - 1][j]);
				Right[i][j] = min(Right[i][j],Right[i - 1][j]);
			}
			rectangle = max(rectangle, h[i][j] * (Right[i][j] - Left[i][j] + 1));
		}
	cout<<rectangle * 3<<endl;
    return 0;
}
