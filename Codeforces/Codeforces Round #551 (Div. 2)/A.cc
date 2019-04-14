/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年04月13日 星期六 22时06分02秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,t,s,d;
	cin >> n >> t;
	pair<int,int> p = make_pair(0,(int)1e9);
	for(int i = 1; i <= n; ++i) {
		cin >> s >> d;
		if(t <= s && s - t <= p.second) {
			p = make_pair(i,s - t);
		}
		int dif = ceil(1.0 * (t - s) / d) * d + s - t;
		if(t > s && dif <= p.second) {
			p = make_pair(i,dif);
		}
	}
	cout << p.first << endl;
    return 0;
}
