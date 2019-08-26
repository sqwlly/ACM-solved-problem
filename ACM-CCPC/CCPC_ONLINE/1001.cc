/*************************************************************************
    > File Name: 1001.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年08月23日 星期五 12时04分43秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int T,a,b;
	cin >> T;
	while(T--) {
		cin >> a >> b;
		long long res = INT_MAX;
		cout << 1 << endl;
		//0001100
		//0101010
/*		vector<int> p,q;
		while(a > 0) {
			p.push_back(a & 1);
			a >>= 1;
		}
		while(b > 0) {
			q.push_back(b & 1);
			b >>= 1;
		}*/
		//1 ^ 1 = 0
		//1 ^ 0 = 1
		//11 ^ 01 = 10
		//101 ^ 001 = 100
		//010 & 100 = 011
	}
    return 0;
}
