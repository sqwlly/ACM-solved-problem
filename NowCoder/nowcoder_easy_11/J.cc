/*************************************************************************
    > File Name: J.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年02月09日 星期六 19时17分29秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;

int d[10010];

void init()
{
	for(int i = 1; i < 10010; ++i) {
		d[i] = i * i;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	init();
	int T,x;
	cin >> T;
	while(T--) {
		cin >> x;
		if(x < 0) {
			cout << -1 << endl;
		}else if(x == 0) {
			cout << 0 << ' ' << 0 << endl;
		}else{
			int a = 1, b = 0;
			for(int i = 2; 1LL * i * i <= 1LL * x; ++i) {
				while(x % d[i] == 0) {
					x /= d[i];
					a *= i;
				}
			}
			cout << a << ' ' << x << endl;
		}
	}
    return 0;
}
