/*************************************************************************
    > File Name: 7-5.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月13日 星期三 22时29分26秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n,x;
	string s;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> x >> s;
		if(x == 0) {
			cout << x << ' ' << s << endl;
		}else{
			int a = (s[0] - '0') * 10 + s[1] - '0';
			int b = (s[3] - '0') * 10 + s[4] - '0';
			int minu = x * 24 * 60 + a * 60 + b;
			int c = minu / (48 * 60);
			minu -= c * 48 * 60;
			int d = minu / 60, e = minu % 60;
			cout << c << ' ';
			printf("%02d:%02d\n",d,e);
		}
	}
    return 0;
}
