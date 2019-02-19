/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年02月19日 星期二 00时23分45秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
typedef long long LL;
using namespace std;
const int N = 2E5+10;
int a[N];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,m,k;
	cin >> n >> m >> k;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a,a+n);
	LL sum = 0;
	if(a[n - 1] == a[n - 2]) {
		sum = 1LL * m * a[n - 1];
	}else{
		LL t1 = m / (k + 1);
		sum = t1 * a[n - 2]; //12
		sum += (1LL*m - t1) * a[n - 1];
	}
	cout << sum << endl;
    return 0;
}
