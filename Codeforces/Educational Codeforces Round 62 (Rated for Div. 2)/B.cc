/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月22日 星期五 23时33分54秒
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
	int T,n;
	string s;
	cin >> T;
	while(T--) {
		cin >> n >> s;
		if(s[0] == '>' || s[s.length() - 1] == '<') {
			cout << 0 << endl;
			continue;
		}
		int ret = 1e6, k = 0;
		for(int i = 0; i < s.length(); ++i) {
			if(s[i] == '>') {
				ret = min(ret, k);
				break;
			}else{
				k++;
			}
		}
		k = 0;
		for(int i = s.length() - 1; i >= 0; --i) {
			if(s[i] == '<') {
				ret = min(ret, k);
				break;
			}else{
				k++;
			}
		}
		cout << ret << endl;
	}
    return 0;
}
