/*************************************************************************
    > File Name: L2_008.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月03日 星期日 12时51分06秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 1010;
string s;

int check(int d)
{
	int a = 1;
	for(int i = d - 1, j = d + 1; i >= 0 && j < s.length(); --i, ++j) {
		if(s[i] == s[j]) {
			a += 2;
		}else{
			break;
		}
	}
	int b = 0;
	for(int i = d, j = d + 1; i >= 0 && j < s.length(); --i, ++j) {
		if(s[i] == s[j]) {
			b += 2;
		}else {
			break;
		}
	}
	return max(a,b);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	getline(cin, s);
	int ans = 0;
	for(int i = 0; i < s.length(); ++i) {
		ans = max(ans, check(i));
	}
	cout << ans << endl;
    return 0;
}
