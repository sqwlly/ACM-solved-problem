/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月13日 星期三 10时39分45秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
map<int,int> cnt;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,x;
	while(cin >> n) {
		cnt.clear();
		for(int i = 0; i < n; ++i) {
			cin >> x;
			cnt[x]++;
		}
		pair<int,int> ans = make_pair(0,0);
		for(auto i : cnt) {
			if(i.second > ans.second) {
				ans = i;
			}
		}
		cout << ans.first << endl;
	}
	return 0;
}
