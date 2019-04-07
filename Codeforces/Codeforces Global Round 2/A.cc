/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年04月06日 星期六 19时34分17秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define P pair<int,int>
using namespace std;
const int N = 3E5+10;
int a[N];
map<int,int> loc_f, loc_l;
priority_queue<P> pq;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		loc_f[a[i]] = loc_l[a[i]] = 0;
	}
	for(int i = 1; i <= n; ++i) {
		if(loc_f[a[i]] == 0) {
			loc_f[a[i]] = i;
		}
		loc_l[a[i]] = i;
	}
	for(auto i : loc_l) {
		pq.push(P(i.second,i.first));
	}
	int ret = 0;
	for(auto i : loc_f) {
		int num = i.first;
		int dx = i.second;
		vector<P> t;
		while(!pq.empty() && pq.top().second == num) {
			t.push_back(pq.top());
			pq.pop();
		}
	//	DEBUG(num);
		P cur = pq.top();
	//	DEBUG(cur.first);
		ret = max(ret, abs(dx - cur.first));
		for(auto j : t) {
			pq.push(j);
		}
	}
	cout << ret << endl;
    return 0;
}
