/*************************************************************************
    > File Name: D.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年02月17日 星期日 09时27分10秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;

bool ok(string s)
{
	int n = s.size();
	for(int i = 0; i < n; ++i) {
		if(s[i] != s[n - i - 1]) return 0;
	}
	return 1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	string s;
	cin >> s;
	int f = 0, n = s.size();
	for(int i = 1; i < n / 2; ++i) {
		if(s[i] != s[i - 1]) {
			f = 1;
			break;
		}
	}
	if(!f) return puts("Impossible"),0;
	for(int i = 0; i < n; ++i) {
		string a = s.substr(0, i);
		string b = s.substr(i, n - i);
		string c = b + a;
		if(c != s && ok(c)) return puts("1"),0;
	}
	puts("2");
    return 0;
}
