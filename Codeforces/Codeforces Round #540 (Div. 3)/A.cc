/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年02月19日 星期二 22时35分02秒
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
	int q;
	long long n,a,b;
	cin >> q;
	while(q--) {
		//x + 2 y = n
		long long ans = 0;
		cin >> n >> a >> b;//a + 2b = cost
		if(n & 1) { // 3 5
			if(a > 1.0 * b / 2) {
				ans = n / 2 * b+ a; // 3 * 2 
			}else{
				ans = n * a;
			}
		}else {
			if(a > 1.0 * b / 2) {
				ans = n / 2 * b;
			}else{
				ans = n * a;
			}
		}
		cout << ans << endl;
	}
    return 0;
}
