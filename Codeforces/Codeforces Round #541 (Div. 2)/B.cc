/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年02月23日 星期六 18时38分09秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
/*
5
1 6
2 7
10 10
16 13
18 18
*/
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,a,b;
	cin >> n;
	int ans = 1,x = 0, y = 0;
	while(n--) {
		cin >> a >> b;
		if(min(a,b) >= max(x,y)) {
	//	if(min(a,b) >= max(x,y) && !(x == a && y == b)) {
			ans += min(a,b) - max(x,y) + 1;
		}
	//	if(x == y && x != 0 && y != 0) ans--;
		if(x == y) ans--;
		x = a, y = b;
	}
	cout << max(ans,1) << endl;
    return 0;
}
