/*************************************************************************
    > File Name: 201712-2.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月16日 星期六 20时47分58秒
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
	int n,k;
	cin >> n >> k;
	vector<int> v;
	bool vis[1020] = {0};
	for(int i = 0; i < n; ++i) {
		v.push_back(i + 1);
	}
	int cnt = n, it = 1, i = 0;
	while(cnt > 1) {
		if((it % k == 0 || it % 10 == k) && vis[i] == 0) {
			vis[i] = 1;
			cnt--;
		}
		if(cnt == 1) break;
		i = (i + 1) % n;
		if(vis[i] == 0)
			it++;
	}
	for(int j = 0; j < n; ++j) {
		if(vis[j] == 0) return cout << v[j] << endl,0;
	}
    return 0;
}
