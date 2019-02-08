/*************************************************************************
    > File Name: C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年02月07日 星期四 22时51分18秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;

int gcd(int a,int b)
{
	return b == 0 ? a : gcd(b, a % b);
}
int d[52] = {2,1,3,1,4,5,5,1,6,21,7,1,8,85,9,73,10,341,11,89,12,1365,13,1,14,5461,15,4681,16,21845,17,1,18,87381,19,1,20,349525,21,299593,22,1398101,23,178481,24,5592405,25,1082401};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int q,a;
	/*
	for(int i = 1; i <= 25; ++i) {
		int t = 0, t1 = (1 << i) - 1;
		for(int j = 1; j < (1 << i) - 2; ++j) {
			t = max(t, __gcd(t1 ^ j, t1 & j));
		}
		cout << i << ' ' << t << endl;
	}
	exit(0);*/
	cin >> q;
	while(q--) {
		cin >> a;
		int f = 0;
		for(int i = 0; i < 52; i += 2) {
			if(a == (1 << d[i]) - 1) {
				cout << d[i + 1] << endl;
				f = 1;
				break;
			}
		}
		if(f) continue;
		int t = -1;
		for(int i = 0; i < a; ++i) {
			if((1 << i) >= a) {
				t = i;
				break;
			}
		}
		if((1 << t) > a) {
			cout << (1 << t) - 1 << endl;
		}else {
			cout << (1 << t) * 2 - 1 << endl;
		}
	}
    return 0;
}
