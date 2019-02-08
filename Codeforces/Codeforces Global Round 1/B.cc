/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年02月07日 星期四 22时07分19秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
int b[100100];

struct node{
	int id, len;
	bool operator < (const node & u) const{
		return len > u.len;
	}
};
priority_queue<node> pq;
bool vis[100100];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n,m,k;
	cin >> n >> m >> k;
	for(int i = 1; i <= n; ++i) {
		cin >> b[i];
	}
	if(n == 1) {
		cout << 1 << endl;
		return 0;
	}
	int res = n, ans = 0;
	for(int i = 2; i <= n; ++i) {
		int len = b[i] - b[i - 1];
		pq.push(node{i - 1,len + 1});
	}
	while(!pq.empty()) {
		if(res == k) {
			ans += res;
			break;
		}else{
			node cur = pq.top();
			pq.pop();
			int i = cur.id;
			int len = cur.len;//10 1 9 
			ans += len;
			res -= 2;
			k--;
			if(vis[i - 1] || vis[i + 1]) {
				ans--;
				res++;
				k++;
			}
			vis[i] = 1;
		}
	}
	cout << ans << endl;
    return 0;
}
