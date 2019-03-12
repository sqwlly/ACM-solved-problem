/*************************************************************************
    > File Name: D.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月11日 星期一 22时23分53秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 5E5+10;
int nxt[N];
string s,t;

void getNext()
{
	int j = 0, k = -1, len = t.length();
	nxt[0] = -1;
	while(j < len) {
		if(k == -1 || t[j] == t[k]) {
			++j, ++k;
			if(t[j] != t[k]) {
				nxt[j] = k;
			}else{
				nxt[j] = nxt[k];
			}
		}else{
			k = nxt[k];
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	cin >> s >> t;
	getNext();
	int one = 0, zero = 0;
	for(int i = 0; i < s.length(); ++i) {
		one += s[i] - '0';
		zero += !(s[i] - '0');
	}
	int it = 0;
	string ans = "";
	while(zero > 0 && one > 0) {
		if(t[it] == '0') {
			if(zero > 0) {
				zero--;
				ans += '0';
			}else{
				break;
			}
		}else{
			if(one > 0) {
				one--;
				ans += '1';
			}else{
				break;
			}
		}
		it++;
		if(it == t.length()) {
			it = nxt[it];
		}
	}
	for(int i = 0; i < zero; ++i) ans += '0';
	for(int i = 0; i < one; ++i) ans += '1';
	cout << ans << endl;
    return 0;
}
