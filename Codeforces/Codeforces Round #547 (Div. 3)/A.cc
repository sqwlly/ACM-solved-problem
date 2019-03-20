/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月19日 星期二 22时33分48秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
typedef long long LL;
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	LL n,m;
	cin >> n >> m;
	for(int i = 0; i < 32; ++i) {
		for(int j = 0; j < 32; ++j) {
			LL t = n << i;
			for(int k = 0; k < j; ++k) {
				t *= 3;
			}
			if(t == m) {
				return cout << (i + j) << endl,0;
			}
		}
	}
	cout << -1 << endl;
    return 0;
}
