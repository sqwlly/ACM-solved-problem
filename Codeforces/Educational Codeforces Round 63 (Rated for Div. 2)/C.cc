/*************************************************************************
    > File Name: C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年04月22日 星期一 23时07分30秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
typedef long long LL;
using namespace std;
const int N = 3E5+10;
LL x[N],p[N],dif[N],g[N];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	LL n,m;
	cin >> n >> m;
	for(int i = 0; i < n; ++i) {
		cin >> x[i];
	}
	for(int i = 1; i < n; ++i) {
		dif[i] = x[i] - x[i - 1];
	}
	LL gcd = __gcd(dif[1],dif[2]);
	for(int i = 3; i < n; ++i) {
		gcd = __gcd(gcd,dif[i]);
	}
//	DEBUG(gcd);
	int j = -1;
	for(int i = 0; i < m; ++i) {
		cin >> p[i];
	//	y[i] = x[0] - p[i];
		if(gcd % p[i] == 0) {
//			DEBUG(i);
			j = i + 1;
			break;
		}
	}
//	y[m] = x[0];
	if(j != -1) {
		cout << "YES" << endl;
		cout << x[0] << ' ' << j << endl;
	}else{
		cout << "NO" << endl;
	}
//	for(int i = 0; i <= m; ++i) {
//		if(y[i])
//	}
    return 0;
}
