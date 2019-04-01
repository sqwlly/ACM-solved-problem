/*************************************************************************
    > File Name: D.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月31日 星期日 23时01分11秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 2E5+10;
int a[N];
map<int,int> cnt;
vector<tuple<int,int,int>> v;
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
		cnt[a[i]]++;
	}
	pair<int,int> t = make_pair(0,0);
	for(auto i : cnt) {
		if(i.second > t.second) {
			t = i;
		}
	}
	int s = -1, e = n;
	for(int i = 0; i < n; ++i) {
		if(a[i] == t.first && s == -1) {
			s = i;
		}
	}
	if(t.second == 1) {
		s = e = n / 2;
	}
	for(int i = s - 1; i >= 0; --i) {
		if(a[i] > a[i + 1]) {
			v.push_back(make_tuple(2,i + 1,i + 2));
			a[i] = a[i + 1];
		}else if(a[i] < a[i + 1]) {
			v.push_back(make_tuple(1,i + 1,i + 2));
			a[i] = a[i + 1];
		}
	}
	
	for(int i = s + 1; i < n; ++i) {
		if(a[i] > a[i - 1]) {
			v.push_back(make_tuple(2,i + 1, i));
			a[i] = a[i - 1];
		}else if(a[i] < a[i - 1]) {
			v.push_back(make_tuple(1,i + 1, i));
			a[i] = a[i - 1];
		}
	}
	cout << v.size() << endl;
	for(auto i : v) {
		cout << get<0>(i) << ' ' << get<1>(i) << ' ' << get<2>(i) << endl;
	}
    return 0;
}
