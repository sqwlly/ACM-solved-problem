/*************************************************************************
    > File Name: 7-2.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月13日 星期三 20时51分44秒
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
	string s,a,b;
	cin >> s >> a >> b;
	reverse(s.begin(),s.end());
	reverse(a.begin(),a.end());
	reverse(b.begin(),b.end());
	int len = min(a.length(), b.length()), dif = abs((int)a.length() - (int)b.length());
	int ans = 0, up;
	for(int i = len; i < len + dif; ++i) {
		if(a.length() < len + dif) {
			a += '0';
		}else{
			b += '0';
		}
	}
	for(int i = 0; i < len; ++i) {
		int radx = s[0] - '0';
		if(radx == 0) radx = 10;
		int x = a[0] - '0', y = b[0] - '0';
		int sum = (x + y + up) % radx;
		up = (x + y + up) / radx;
		ans = ans * 10 + sum;
	}
	cout << ans << endl;
    return 0;
}
