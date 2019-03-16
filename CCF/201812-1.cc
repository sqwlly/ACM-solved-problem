/*************************************************************************
    > File Name: 201812-1.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月16日 星期六 12时35分16秒
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
	int r,y,g,k,n,t;
	long long ans = 0;
	cin >> r >> y >> g >> n;
	for(int i = 0; i < n; ++i) {
		cin >> k >> t;
		if(k == 0) {
			ans += t;
		}else if(k == 1) {
			ans += t;
		}else if(k == 2) {
			ans += t +  r;
		} 
	}
	cout << ans << endl;
    return 0;
}
