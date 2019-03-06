/*************************************************************************
    > File Name: C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月05日 星期二 23时35分17秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 5050;
struct node{
	int l,r;
	bool operator < (const node & u) const {
		return l < u.l;
	}
}a[5050];
int vis[5050];

int n,q;
int sum1[N],sum2[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int L = 1e9, R = 0, len = 0;
	cin >> n >> q;
	for(int i = 0; i < q; ++i) {
		cin >> a[i].l >> a[i].r;
		vis[a[i].l]++;
		vis[a[i].r + 1]--;
	}
	for(int i = 1; i <= n; ++i) {
		vis[i] = vis[i - 1] + vis[i];
		if(vis[i]) len++;
	}
	for(int i = 1; i <= n; ++i) {
		sum1[i] = sum1[i - 1];
		sum2[i] = sum2[i - 1];
		if(vis[i] == 1) {
			sum1[i]++;
		}else if(vis[i] == 2) {
			sum2[i]++;
		}
	}
	sort(a, a + q);
	int ans = 0, cnt1, cnt2;
	for(int i = 0; i < q - 1; ++i) {
		for(int j = i + 1; j < q; ++j) {
			int one = sum1[a[i].r] - sum1[a[i].l - 1] + sum1[a[j].r] - sum1[a[j].l - 1];
			int t = one;
			if(a[i].r >= a[j].l) { //区间交集减去被覆盖数为2的
				t += (sum2[min(a[i].r,a[j].r)] - sum2[max(a[j].l, a[i].l) - 1]);
			}
			ans = max(ans , len - t);
		}
	}
	cout << ans << endl;

    return 0;
}
