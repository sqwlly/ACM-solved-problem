/*************************************************************************
    > File Name: 7-14.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月13日 星期三 22时13分26秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;

struct node{
	double v;
	int s;
	bool operator < (const node &u) const{
		return v > u.v;
	}
}a[200];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
//    ios::sync_with_stdio(false); cin.tie(0);
	string s; double t;
	int n,k;
	cin >> n >> k;
	for(int i = 0; i < n; ++i) {
		cin >> a[i].s >> a[i].v;
	//	cin >> s >> t;
	//	v.push_back(make_pair(t,s));
	}
	sort(a, a + n);
	printf("%d %g\n",a[k - 1].s, a[k - 1].v);
//	sort(v.begin(), v.end());
//	cout << v[n - k].second << ' ';
//	printf("%g\n",v[n - k].first);
    return 0;
}
