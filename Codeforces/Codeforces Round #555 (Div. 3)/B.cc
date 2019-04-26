/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年04月26日 星期五 22时40分43秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
int f[10],cnt[10];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int x;
	for(int i = 0; i < 9; ++i) {
		cin >> f[i + 1];
		cnt[i + 1] = 1;
	}
	int id = 0;
	for(int i = 0; i < n; ++i) {
		if(f[s[i] - '0'] > s[i] - '0') {
			for(int j = i; j < n; ++j) {
				if(f[s[j] - '0'] < s[j] - '0') {
					break;
				}
				s[j] = f[s[j] - '0'] + '0';
			}
			break;
		}
	}
	cout << s << endl;
    return 0;
}
