/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年01月31日 星期四 20时58分06秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
const int N = 1E5+10;
struct node{
	int t,d;
}cust[N];

struct food{
	int c,d,id;
	bool operator < (const food & u) const {
		if(d == u.d) {
			return id > u.id;
		}
		return c > u.c;
	}
};
priority_queue<food> pq;
int a[N],c[N],d[N];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n,m;
	for(int i = 0; i < n; ++i) {
		scanf("%d",&a[i]);
	}
	for(int i = 0; i < n; ++i) {
		scanf("%d",&c[i]);
	}
	for(int i = 0; i < n; ++i) {
		pq.push(food{c[i],d[i],i});
	}
	for(int i = 0; i < m; ++i) {
		scanf("%d%d",&cust[i].t,&cust[i].d);
	}
	long long ans = 0, tmp = 0;
	for(int i = 0; i < m; ++i) {
		tmp = 0;
		int t = cust[i].t;
		int num = cust[i].d;
		if(num > c[t]) {
			tmp += d[t] * c[t];
			num -= c[t];
			if(pq.empty()) continue;
			while(!pq.empty()) {
				food cur = pq.top(); pq.pop();
				cur.c = min(cur.c,c[cur.id]);
				if(cur.c >= num) {
					tmp += 1LL * cur.d * num;
					cur.c -= num;
					c[cur.id] -= num;
					if(cur.c != 0)
						pq.push(cur);
					break;
				}else{
					tmp += 1LL * cur.c * cur.d;
					c[cur.id] = 0;
				}
			}
		}else{
			c[t] -= num;
		}
		ans += tmp;
	}
	cout << ans << endl;
    return 0;
}
