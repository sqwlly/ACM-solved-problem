/*************************************************************************
    > File Name: D.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年04月05日 星期五 17时05分21秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
#define P pair<char,int>
using namespace std;

vector<pair<char,int>> v;

bool cmp(const P &u, const P &r)
{
	return u.first == r.first;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	string s;
	cin >> s;
	for(int i = 0; i < s.length(); ++i) {
		v.push_back(make_pair(s[i],i));
	}
	sort(v.begin(), v.end(),[] (const P &u, const P &r) ->int {
		if(u.first == r.first) return u.second < r.second;
		return u.first < r.first;
	});
	v.erase(unique(v.begin(), v.end(), cmp), v.end());
	sort(v.begin(), v.end(),[] (const P &u, const P &r) ->int {
		return u.second < r.second;		
	});
	for(int i = 0; i < v.size(); ++i) {
		cout << v[i].first;
	}
    return 0;
}
