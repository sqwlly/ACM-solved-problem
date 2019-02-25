/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年02月24日 星期日 23时51分42秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 1E5+10;
struct node{
	int v,id;
	bool operator < (const node & u) const{
		return v < u.v;
	}
}a[N];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i <= 2 * n; ++i) {
		cin >> a[i].v;
		a[i].id = i;
	}
	sort(a+1,a + 2 * n + 1);
	long long ans = 0, pre1 = 1, pre2 = 1;
	for(int i = 1; i <= 2 * n; i += 2) {
		//DEBUG(a[i].id);
		//DEBUG(a[i + 1].id);
		int p = abs(a[i].id - pre1) + abs(a[i + 1].id - pre2);
		int q = abs(a[i].id - pre2) + abs(a[i + 1].id - pre1);
		if(p > q) {
			ans += q;
			pre2 = a[i].id;
			pre1 = a[i + 1].id;
		}else{
			ans += p;
			pre1 = a[i].id;
			pre2 = a[i + 1].id;
		}
	}
	cout << ans << endl;
    return 0;
}
