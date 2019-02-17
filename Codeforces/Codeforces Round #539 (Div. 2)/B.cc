/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年02月17日 星期日 09时06分33秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
const int N = 5E5+10;
int a[N];
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n;
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> n;
	long long sum = 0, ans = 1e18;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		sum += a[i];
	}
	ans = sum;
	sort(a, a + n);
	for(int i = 1; i < n; ++i) {
		for(int j = 2; j * j <= a[i]; ++j) {
			if(a[i] % j == 0) {
				ans = min(ans, sum - a[i] + a[i] / j + a[0] * (j - 1));
			}
		}
	}
	cout << ans << endl;
    return 0;
}
