#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
const int N = 100100;
int a[N], n;
LL plant[N], m;
bool love(LL minH)
{
	memset(plant, 0, sizeof plant);
	for(int i = 1; i <= n; ++i) {
		if(m > 0) {
			plant[i] += a[i];
			m--;
		}
		if(m <= 0) break;
		if(plant[i] >= minH) continue; //如果走完这一步已经满足就不需要判断

		if(minH > plant[i]) {
			LL cnt = 1LL * ceil((minH - plant[i]) * 1.0 / a[i]);
			if(cnt * 2 <= m) {
				m -= cnt * 2;
				plant[i] += a[i] * cnt;
				plant[i + 1] += a[i + 1] * cnt;
			}else break;
			if(m <= 0) break;
		}
	}
	for(int i = 1; i <= n; ++i)
		if(plant[i] < minH) return 0;
	return 1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int T;
	scanf("%d",&T);
	while(T--) {
		scanf("%d %lld",&n,&m);
		memset(a, 0, sizeof a);
		LL l = 1, r = 0, ans = 0, t = m;
		for(int i = 1; i <= n; ++i) {
			scanf("%d", a + i);
			r = max(r, a[i] * m);
		}
		if(m == 0) {
			puts("0");
			continue;
		}
		while(l <= r) {
			LL mid = l + (r - l) / 2;
			m = t;
			if(love(mid)) {
				ans = mid;
				l = mid + 1;
			}else{
				r = mid - 1;
			}
		}
		printf("%lld\n", ans);
	}

    return 0;
}
