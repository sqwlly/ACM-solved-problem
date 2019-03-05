/*************************************************************************
    > File Name: L2_003.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月05日 星期二 13时18分36秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
struct node{
	double d,c;
	bool operator < (const node & u) const {
		return c * u.d > u.c * d;
	}
}a[1024];

// c     u.c
//--- > -----
// d     u.d 
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,D;
	cin >> n >> D;
	for(int i = 0; i < n; ++i) {
		cin >> a[i].d;
	}
	for(int i = 0; i < n; ++i) {
		cin >> a[i].c;
	}
	sort(a, a + n);
	double ans = 0;
	for(int i = 0; i < n; ++i) {
		if(a[i].d <= D) {
			D -= a[i].d;
			ans += a[i].c;
		}else{
			ans += a[i].c * 1.0 / a[i].d * D; //45 / 10 * 5
			break;
		}
	}
	cout << fixed << setprecision(2) << ans << endl;
    return 0;
}
