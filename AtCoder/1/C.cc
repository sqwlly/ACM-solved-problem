/*************************************************************************
    > File Name: C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年02月16日 星期六 20时32分55秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;

int main()
{
	int n,x;
	long long ans = 0, gcd = 0, a; 
	cin >> n >> a >> x;
	gcd = __gcd(a,1LL*x);
	for(int i = 2; i < n; ++i) {
		scanf("%d",&x);
		gcd = __gcd(1LL*x,gcd);
	}
	cout << gcd << endl;
    return 0;
}
