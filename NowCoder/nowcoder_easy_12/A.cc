/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月13日 星期三 15时24分58秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 1E5+10;
struct node{
	int l,r;
	bool operator < (const node& u) const {
		if(l == u.l) return r > u.r;
		return l < u.l;
	}
}a[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,m;
	cin >> n >> m;
	for(int i = 0; i < m; ++i) {
		cin >> a[i].l >> a[i].r;
	}
	sort(a, a + m);
	int pre = 0, cnt = 0;
	for(int i = 0; i < m;) {
		int maxR = 0;
		while(a[i].l <= pre + 1 && i < m) {
			maxR = max(maxR, a[i].r);
			i++;
		}
		if(maxR == 0) break;
		pre = maxR;
		cnt++;
		if(pre >= n) return cout << cnt << endl,0;
	}
	cout << -1 << endl;
    return 0;
}
