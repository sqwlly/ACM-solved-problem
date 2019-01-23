/*************************************************************************
    > File Name: A1.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年01月23日 星期三 17时38分35秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
const int N = 200100;
int x[N], y[N];
bool vis[N];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n,m;
	cin >> n >> m;
	for(int i = 1; i <= 2 * n; ++i) {
		scanf("%d %d",&x[i], &y[i]);
	}
	long long ans = 0;
	int a[4] = {0};
	for(int i = 1; i < n; i++) {
		a[0] = abs(x[i] - x[i * 2 + 1]) + abs(y[i] - y[i * 2 + 1]);
		a[1] = abs(x[i] - x[i * 2 + 2]) + abs(y[i] - y[i * 2 + 2]);
		a[2] = abs(x[i + 1] - x[i * 2 + 1]) + abs(y[i + 1] - y[i * 2 + 1]);
		a[3] = abs(x[i + 1] - x[i * 2 + 2]) + abs(y[i + 1] - y[i * 2 + 2]);
		int min1 = *min_element(a, a + 4);
		if(min1 == a[0]) {
			vis[i * 2 + 1] = vis[i] = 1;
		}else if(min1 == a[1]) {
			vis[i * 2 + 2] = vis[i] = 1;
		}else if(min1 == a[2]) {
			vis[i * 2 + 1] = vis[i + 1] = 1;
		}else if(min1 == a[3]) {
			vis[i * 2 + 2] = vis[i + 1] = 1;
		}
		ans += min1;
	}
	ans += abs(x[2 * n] - x[2 * n - 1]) + abs(y[2 * n] - y[2 * n - 1]);
	for(int i = 1; i <= 2 * n; ++i) {
		if(vis[i] == 0) {
			for(int k = i + 1, t = 0; t < 2 && k <= 2 * n; ++t, ++k) {
				if(vis[k] == 0) {
					ans += abs(x[i] - x[k]) + abs(y[i] - y[k]);
					break;
				}
			}
		}
	}
	cout << ans << endl;
    return 0;
}
