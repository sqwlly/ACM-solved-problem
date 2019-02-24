/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年02月23日 星期六 17时56分59秒
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
	long long w1,h1,w2,h2;
	cin >> w1 >> h1 >> w2 >> h2;
	long long ans = 0;
	ans += w1 + 2 + h1 * 2;
	ans += w2 + 2 + h2 * 2;
	if(w1 > w2) {
		ans += w1 - w2;
	}else if(w1 < w2){
		ans += w2 - w1;
	}
	cout << ans << endl;
    return 0;
}
