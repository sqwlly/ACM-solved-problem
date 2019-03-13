/*************************************************************************
    > File Name: L1_06.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月12日 星期二 15时49分53秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
vector<int> v;
bool ok(string s,int x)
{
	v.clear();
	int ans = 0;
	for(int i = 0; i < s.length(); ++i) {
		if(ans < x) ans = ans * 10 + 1;
		if(ans >= x || v.size()) {
			v.push_back(ans / x);
			ans = ans % x;
		}
	}
	return ans == 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int x;
	cin >> x;
	string s = "";
	for(int i = 1; i; ++i) {
		s += '1';
		if(ok(s,x)) {
			for(int j = 0; j < v.size(); ++j) {
				cout << v[j];
			}
			cout << ' ' << i << endl;
			break;
		}
	}
    return 0;
}
