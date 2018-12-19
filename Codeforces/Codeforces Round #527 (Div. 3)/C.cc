/*************************************************************************
    > File Name: C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年12月18日 星期二 22时56分32秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
int n;
string s[202];
char ans[204];

bool solve(string pre,string suf)
{
	memset(ans, 0, sizeof ans);
	for(int i = 1; i <= n; ++i) {
		bool f = 1;
		for(int j = 0; j < 2 * n - 2; ++j) {
			if(i == s[j].size()) {
				if(pre.substr(0,i) == s[j] && f) {
					ans[j] = 'P';
					f = 0;
				}else if(suf.substr(n - i - 1, i) == s[j]){
					ans[j] = 'S';
				}
				if(!ans[j]) return 0;
			}
		}
	}
	return 1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	cin >> n;
	string suf,pre;
	for(int i = 0; i < 2 * n - 2; ++i) {
		cin >> s[i];
		if(s[i].size() == n - 1) {
			if(!pre.size()) {
				pre = s[i];
			}else{
				suf = s[i];
			}
		}
	}
	if(solve(suf,pre)) {
		puts(ans);
	}else if(solve(pre,suf)){
		puts(ans);
	}

    return 0;
}
