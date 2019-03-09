/*************************************************************************
    > File Name: D.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月07日 星期四 09时18分51秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
typedef long long LL;
using namespace std;
const int N = 2E5+10;
LL a[N],b[N],cnt[N],n,k;
priority_queue<int, vector<int>, greater<int> > pq;

void clear(auto &p)
{
	priority_queue<int, vector<int>, greater<int> > t;
	swap(t,p);
}

bool ok(LL d) 
{
	LL dx = k - 1;
	memset(cnt, 0, sizeof cnt);
	for(int i = 0; i < n; ++i) {
		if(b[i] == 0) continue;
		LL ret = a[i];
		while(ret < (k - 1) * b[i]) {
			int t = ret / b[i] + 1;
			if(t <= k) cnt[t]++;
			if(dx == 0) return 0;
			dx--;
			ret += d;
		}
	}
	for(int i = 1; i <= k; ++i) {
		cnt[i] += cnt[i - 1];
		if(cnt[i] > i) return 0;
	}
	return 1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for(int i = 0; i < n; ++i) {
		cin >> b[i];
	}
	LL l = 0, r = LLONG_MAX / 2, ans = -1;
	while(l <= r) {
		LL mid = l + r >> 1;
		if(ok(mid)) {
			r = mid - 1;
			ans = mid;
		}else{
			l = mid + 1;
		}
	}
	cout << ans << endl;
    return 0;
}
