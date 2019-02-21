/*************************************************************************
    > File Name: D2.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年02月21日 星期四 20时43分33秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
typedef long long LL;
using namespace std;
const int N = 2E5 + 10;
int a[N], n, m;

bool ok(int d)
{
	LL sum = 0;
	for(int i = 0; i < n; ++i) {
		sum += max(0,a[i] - i / d);
	}
//	DEBUG(d); DEBUG(sum);
	return sum >= m;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	sort(a, a + n, greater<int>());
	int l = 1, r = INT_MAX / 2, ans = -1;
	while(l < r) {
		int mid = (l + r) >> 1;
		if(!ok(mid)) {
			l = mid + 1;
		}else{
			r = mid - 1;
			ans = mid;
		}
	}
//	DEBUG(l); DEBUG(r);
	if(ok(l)) ans = l;
	else if(ok(r)) ans = r;
	cout << ans << endl;
    return 0;
}
