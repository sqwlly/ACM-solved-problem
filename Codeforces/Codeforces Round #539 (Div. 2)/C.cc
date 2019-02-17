/*************************************************************************
    > File Name: C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年02月17日 星期日 09时21分59秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
typedef long long LL;
const int N = 3E5+10;
using namespace std;
map<int,int> m[2];
int a[N];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,x,sum = 0; 
	LL ans = 0;
	cin >> n;
	m[0 & 1][0]++;
	for(int i = 1; i <= n; ++i) {
		cin >> x;
		sum ^= x;
		ans += m[(i & 1)][sum];
		m[(i & 1)][sum]++;
	}
	cout << ans << endl;
    return 0;
}
