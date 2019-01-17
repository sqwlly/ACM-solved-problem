/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年12月30日 星期日 22时28分22秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int y,b,r;
	cin >>y >> b >> r;
	int ans = 0;
	for(int i = 1; i <= y; ++i) {
		int b1 = 0;
		if(i + 1 <= b) {
			b1 = i + 1;
		}else{
			continue;
		}
		int r1 = 0;
		if(b1 + 1 <= r) {
			r1 = b1 + 1;
		}else{
			continue;
		}
		
		ans = max(ans,b1+r1+i);
	}
	cout << ans << endl;
    return 0;
}
