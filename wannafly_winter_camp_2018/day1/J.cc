/*************************************************************************
    > File Name: J.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com
    > Created Time: 2019年01月20日 星期日 13时50分56秒
 ************************************************************************/
#include<bits/stdc++.h>
#define pair < int,int >  P;
using namespace std;
typedef long long LL;
vector<int> v[1011];

struct node{
    int cost, id;
    bool operator < (const node & u) const{
        return cost < u.cost;
    }
}f[1010];
struct co{
    int id,cnt;
    bool operator < (const co & u) const{
        return cnt < u.cnt;
    }
};
int count1[1002];
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
#endif
    priority_queue<co> pq;
    int n, m, a, c;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        cin >> a >> c;
        v[c].push_back(a);
        f[i].cost = a;
        f[i].id = c;
        count1[c]++;
    }
    for (int i = 1; i <= n; ++i) {
        if (count1[i])
            pq.push(co{i, count1[i]});
    }
    sort(f, f + m);
     int maxcnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (v[i].size() != 0) {
            sort(v[i].begin(), v[i].end(), greater<int>());
        }
           maxcnt = max(maxcnt,(int)v[i].size());
    }
    int cnt = 0;
    LL ans = 0;
    for (int i = 0; i < m; ++i) {
        if (cnt > pq.top().cnt) break;
		LL t = 1e18;
		int c = 0;
		if(cnt == pq.top().cnt - 1) {
			for(int j = 1; j <= n; ++j) {
				if(count1[j] == pq.top().cnt) {
					if(t > v[j].back()) {
						t = v[j].back();
						c = j;
					}
				}
			}
			if(c) {
				co cc = co{c, pq.top().cnt - 1};
				pq.pop();
				pq.push(cc);
				v[c].pop_back();
			}
		}
        LL Acost = 0;
        Acost = ans + f[i].cost;
        LL Bcost = 0;
		if(t == 1e18) t = 0;
        Bcost = ans + t;
        if (Acost >= Bcost || c) {
            ans += t;
        } else {
            ans += f[i].cost;
        }
        cnt++;
    }
    cout << ans << endl;
    return 0;
}
