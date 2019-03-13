/*************************************************************************
    > File Name: E.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月13日 星期三 15时18分20秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
typedef long long LL;
using namespace std;
const int N = 2E5+10;
int a[N],n,k;

bool check(int x)
{
	LL ret = 0;
	for(int i = 0; i < n; ++i) {
		ret += a[i] / x;
	}
	return ret >= k;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	cin >> n >> k;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int l = 1, r = INT_MAX >> 1;
	while(l <= r) {
		int mid = l + r >> 1;
		if(check(mid)) {
			l = mid + 1;
		}else{
			r = mid - 1;
		}
	}
	cout << l - 1 << endl;
    return 0;
}
