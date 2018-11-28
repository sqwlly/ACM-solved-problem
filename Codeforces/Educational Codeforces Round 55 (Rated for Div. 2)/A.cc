/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年11月28日 星期三 22时34分48秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int T,n,x,y,d;
	cin>>T;
	while(T--) {
		cin >> n >> x >> y >> d;
		int t = abs(y - x), cnt = 1e9;
		if(t % d == 0) {
			cnt = t / d;
		}
		if((y - 1) % d == 0){
			cnt = min(cnt, (int)ceil(1.0 * x / d) + (y - 1) / d);
		}
		if((n - y) % d == 0) {
			cnt = min(cnt, (int)ceil((n - x) * 1.0 / d) + (n - y) / d);
		}
		if(cnt != 1e9)
			cout << cnt << endl;
		else
			puts("-1");
	}
    return 0;
}
