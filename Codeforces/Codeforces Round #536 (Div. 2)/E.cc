/*************************************************************************
    > File Name: E.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年02月01日 星期五 12时13分09秒
 ************************************************************************/

#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
const int N = 1E5+10;
struct node{
	int s,t,d,w;
	bool operator < (const node & u) const{
		if(w == u.w) return d < u.d;
		return w < u.w;
	}
};

bool cmp(const node & a, const node & b){ return a.s < b.s; }

priority_queue<node> pq;

vector<node> v;
LL dp[N][201], got[N], nxt[N];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n,m,k,s,t,d,w;
	cin >> n >> m >> k;
	for(int i = 0; i < k; ++i) {
		cin >> s >> t >> d >> w;
		v.push_back(node{s,t,d,w});
	}
	sort(v.begin(),v.end(),cmp);
	int cur = 0;
	//1  4			
	//6  4 + 7      
	//11 4 + 7 + 9 <!> 11 <!>12 --> 4 + 7 = 11
	for(int i = 1; i <= n; ++i) {
		while(cur < k && v[cur].s <= i) 
			pq.push(v[cur++]);
		while(!pq.empty() && pq.top().t < i) pq.pop();
		if(!pq.empty()){
			node t = pq.top(); 
			got[i] = t.w;
			nxt[i] = t.d + 1;
		}else{
			got[i] = 0;
			nxt[i] = i + 1;
		}

	}
	memset(dp,0x3f,sizeof dp);
	dp[n + 1][0] = 0;
	for(int i = n; i > 0; --i) {
		dp[i][0] = dp[nxt[i]][0] + got[i];
	}
	for(int i = n; i >= 1; --i) {
		for(int j = 0; j <= m; ++j) {
			dp[i][j] = min(dp[i][j], dp[nxt[i]][j] + got[i]);
			dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
		}
	}
	LL ans = *min_element(dp[1],dp[2]);
	cout << ans << endl;
    return 0;
}
