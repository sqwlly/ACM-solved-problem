/*************************************************************************
    > File Name: G.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年01月27日 星期日 14时02分38秒
 ************************************************************************/

#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
const int N = 2010;
int n,m;
string s[N];
LL sum[N][N], f[N * N];

void update(LL ret,int x,int y)
{
	for(int i = x; i >= 1; --i) {
		for(int j = y; j >= 1; --j) {
			f[ret - sum[i][j]]++;
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	cin >> n >> m;
	for(int i = 0; i < n; ++i) {
		cin >> s[i];
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + ((s[i - 1][j - 1] == '1' )? 1 : 0);
			if(s[i - 1][j - 1] == '1') 
				f[1]++;
		}
	}
	LL ans = 0;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			update(sum[i][j],i,j);
		}
	}
	for(int i = 1; i <= n * m; ++i) {
		cout<<f[i]<<endl;
		ans += i * f[i];
	}
	cout << ans << endl;
    return 0;
}
