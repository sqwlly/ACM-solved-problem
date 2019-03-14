/*************************************************************************
    > File Name: J.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月13日 星期三 23时41分18秒
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
	string s,t;
	int n;
	cin >> s >> n;
	int len = s.length();
	for(int i = 0; i < n; ++i) {
		cin >> t;
		int k = 0;
		for(int j = 0; j < len; ++j) {
			if(s[j] == t[k]) {
				k++;
			}
			if(k == t.size()) break;
		}
		cout << (k == t.size() ? "Yes" : "No") << endl;
	}
    return 0;
}
