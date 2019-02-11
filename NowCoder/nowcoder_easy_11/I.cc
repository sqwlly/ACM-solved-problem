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
int a[N],b[N];
LL C[N],A[35][2],B[35][2];
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
	for(int i = 1; i <= n; ++i) {
		for(int j = 0; j < 31; ++j) {
			A[j][(a[i] >> j) & 1]++;
			B[j][(b[i] >> j) & 1]++;
			LL c = A[j][1] * B[j][0] % mod + A[j][0] * B[j][1] % mod;
			C[i] += c * (1 << j) % mod;
			C[i] %= mod;
		}
	}
	for(int i = 1; i <= n; ++i) {
		printf("%lld%c",C[i],i == n ? '\n' :' ');
	}
    return 0;
}
