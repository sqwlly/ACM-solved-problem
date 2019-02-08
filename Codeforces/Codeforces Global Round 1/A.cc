/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年02月07日 星期四 21时33分48秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
const int N = 1e5+10;

typedef long long LL;
//

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int b,k;
	cin >> b >> k;
	LL sum = 0;
	int x, f = 0;
	for(int i = k - 1; i >= 0; --i) {
		cin >> x;
		if(x % 2 == 1) {
			if(b % 2 == 1 || i == 0) f++; 
		}
	//	sum += x * qpow(b,k);
	}
	puts((f % 2 == 0)?"even":"odd");
    return 0;
}
