/*************************************************************************
    > File Name: E.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年04月01日 星期一 21时36分47秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 2E5+10;

int ret[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n;
	string s,b;
	cin >> n >> s >> b;
	int c = 0;
	for(int i = n - 1; i >= 0; --i) {
		int t = s[i] + b[i] - 'a' * 2 + c;
		int r = t % 26;
		c = t / 26;
		if(t >= 26 && i == 0) r = t;
		ret[i] = r;
	}
	for(int i = 0; i < n; ++i) {
		if(ret[i] & 1) ret[i + 1] += 26;
		ret[i] >>= 1;
		cout << char(ret[i] + 'a');
	}
    return 0;
}
