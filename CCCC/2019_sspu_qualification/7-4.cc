/*************************************************************************
    > File Name: 7-4.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月13日 星期三 21时47分43秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,w,h;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> h >> w;
		double q = (h - 100) * 0.9 * 2;
		double t = fabs((h - 100) * 0.9 * 2 - w);
		if(t < q * 0.1) {
			cout << "You are wan mei!" << endl;
		}else if(w > q) {
			cout << "You are tai pang le!" << endl;
		}else{
			cout << "You are tai shou le!" << endl;
		}
	}
    return 0;
}
