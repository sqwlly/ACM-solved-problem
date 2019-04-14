/*************************************************************************
    > File Name: D.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年04月12日 星期五 19时48分13秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
typedef long long LL;
using namespace std;
const int N = 5E6+10;
LL a[N], sum[N];
int bit[50];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i];
		sum[i] = sum[i - 1] | a[i];
	}
	LL ret = 0;
	for(int i = 1; i <= n; ++i) {
		int t = a[i];
		for(int r = 0 ; r <= 32; r++) {
			bit[r] += (t & 1);
			t >>= 1;
		}
	}
	for(int i = 1; i <= n; ++i) {
		int t = a[i];
		vector<int> v(bit, bit + 33);
		for(int r = 0; r <= 32; r++) {
			if(v[r] > 0 && (t & 1)) {
				v[r]--;
			}
			t >>= 1;
		}
		LL w = 0;
		int r = 32;
		while(v[r] == 0) r--;
		for(; r >= 0; --r) {
			w = w * 2 + (v[r] > 0);
		}
		ret = max(ret, w);
	}
	cout << ret << endl;
    return 0;
}
