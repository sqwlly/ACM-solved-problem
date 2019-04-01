/*************************************************************************
    > File Name: C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月31日 星期日 22时44分49秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 2E5+10;

map<int,int> cnt;
set<int> inc,asc;
int a[N];
vector<int> t;
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
	sort(a, a + n);
	for(const auto &i : cnt) {
		if(i.second >= 3) {
			return cout << "NO" << endl,0;
		}
		if(i.second == 2) {
			inc.insert(i.first);
			asc.insert(i.first);
		}else{
			inc.insert(i.first);
		}
	}
	cout << "YES" << endl;
	cout << inc.size() << endl;
	for(auto i : inc) cout << i << ' ';
	cout << endl;
	for(auto i : asc) t.push_back(i);
	cout << asc.size() << endl;
	for(int i = t.size() - 1; i >= 0; --i) {
		cout << t[i] << ' ';
	}
	cout << endl;
    return 0;
}
