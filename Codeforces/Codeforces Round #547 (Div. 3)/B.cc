/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月19日 星期二 22时45分43秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 4E5+10;
int a[N];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		a[i + n] = a[i];
	}
	int cnt = 0, ans = 0;
	for(int i = 0; i < 2 * n; ++i) {
		if(a[i] == 1) {
			cnt++;
			ans = max(ans, cnt);
		}else{
			cnt = 0;
		}
	}
	cout << ans << endl;
    return 0;
}
