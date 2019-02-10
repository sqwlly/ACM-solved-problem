/*************************************************************************
    > File Name: I.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年02月09日 星期六 19时24分03秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
//a2 *    b1
//a3 **   b1 b2
//a4 ***  b1 b2 b3
//a5 **** b1 b2 b3 b4
//a6 *****
//
//b2 *    a1	     //b2 ^ a1
//b3 **   a1 a2		 //b3 ^ a1 + b3 ^ a2
//b4 ***  a1 a2 a3   //b4 ^ a1 + b4 ^ a2 + b4 ^ a3 = b4 ^ sumA[3]
//b5 **** a1 a2 a3 a4
//b6 *****
//1101 + 1101 + 1101    1101        01101
//0101   0111   0100  + 1110      ^ 10110
//1000 + 1010 + 1001 = 11011      = 11011
//1 2 3 4
//0 1 0 1
//0 2 1 2
//0 3 1 2
typedef long long LL;
const int N = 1E5+10, mod = 1e9 + 7;
LL sumA[N],sumB[N],c[N];
int a[N],b[N];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		scanf("%d",&a[i]);
	}
	for(int i = 1; i <= n; ++i) {
		scanf("%d",&b[i]);
	}
	LL pre = 0, t;
	for(int i = 1; i <= n; ++i) {
		c[i] = (c[i - 1] + (a[i] ^ b[i])) % mod;
		for(int j = 1; j < i; ++j)
			c[i] += (a[i] ^ b[j])%mod;
		for(int j = 1; j < i; ++j)
			c[i] += (b[i] ^ a[j]) % mod;
	}
	for(int i = 1; i <= n; ++i) {
		printf("%lld%c",c[i],i == n ? '\n' :' ');
	}
    return 0;
}
