/*************************************************************************
    > File Name: C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年02月23日 星期六 19时18分29秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int a[102] = {0}, ans[102] = {0};
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a,a + n);
	int t = 0;
	for(int i = 0, j = n - 1; i < n / 2; ++i, --j) {
		ans[i] = a[t++];
		ans[j] = a[t++];
//		DEBUG(ans[i]);
//		DEBUG(ans[j]);
	}
	if(n & 1) ans[n / 2] = a[n - 1];
	for(int i = 0; i < n; ++i) {
		cout << ans[i] << ' ';
	}
    return 0;
}
