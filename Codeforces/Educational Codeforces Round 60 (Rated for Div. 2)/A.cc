/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年02月18日 星期一 23时18分39秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 1E5+10;
int a[N];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	int ans = 2, cnt = 1, x = 0;
	double av = 0, sum = 0;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		sum += a[i];
		if(a[i] == a[i - 1]) {
			cnt++;
			if(fabs(sum / cnt - av) < 1e-6) {
				ans = max(ans,cnt);
				av = sum / cnt;
			}
		}else{
			cnt = 1;
			sum = a[i];
		}
	}
	if(ans > n) ans = n;
	cout << ans << endl;
    return 0;
}
