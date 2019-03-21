/*************************************************************************
    > File Name: F.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月20日 星期三 21时55分30秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 1501;
map<int,vector<pair<int,int>>> sum;
int a[N];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for(int i = 0; i < n; ++i) {
		int ret = 0;
		for(int j = i; j < n; ++j) {
			ret += a[j];
			sum[ret].push_back(make_pair(j + 1,i + 1));
		}
	}
	vector<pair<int,int>> ans;
	for(auto it : sum) {
		sort(it.second.begin(),it.second.end());
		it.second.erase(unique(it.second.begin(),it.second.end()),it.second.end());
		int r = 0;
		vector<pair<int,int>> ret;
		for(auto i : it.second) {
			if(i.second > r) {
				r = i.first;
				ret.push_back(i);
			}
		}
		if(ret.size() > ans.size()) {
			ans = ret;
		}
	}
	cout << ans.size() << endl;
	for(auto i : ans) {
		cout << i.second << ' ' << i.first << endl;
	}
    return 0;
}
