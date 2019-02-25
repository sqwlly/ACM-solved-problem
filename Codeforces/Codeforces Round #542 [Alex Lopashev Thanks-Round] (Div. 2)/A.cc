/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年02月24日 星期日 23时38分05秒
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
	int n, a[102] = {0};
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int ans = 0;
	for(int i = -1000; i <= 1000; ++i) {
		if(i == 0) continue;
		int cnt = 0;
		for(int j = 0; j < n; ++j) {
			double t = ceil(1.0 * a[j] / i);
			if(t > 0) {
				cnt++;
			}
		}
		if(cnt >= ceil(1.0 * n / 2)) {
			ans = i;
			break;
		}
	}
	cout << ans << endl;
    return 0;
}
