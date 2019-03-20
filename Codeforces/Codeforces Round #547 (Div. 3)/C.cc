/*************************************************************************
    > File Name: C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月19日 星期二 22时52分24秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
typedef long long LL;
using namespace std;
const int N = 2E5+10;
int a[N],q[N],vis[N];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n, f = 1, idx = 0;
	LL MIN = 0;
	cin >> n;
	for(int i = 1; i <= n - 1; ++i) {
		cin >> q[i];
	}
	LL sum = 0;
	for(int i = 1; i < n; ++i) {
		sum += q[i];
		if(MIN > sum) {
			MIN = sum;
			idx = i;
		}
	}
	a[idx] = 1;
	for(int i = idx - 1; i >= 0; --i) {
		a[i] = a[i + 1] - q[i + 1];
	}
	for(int i = idx + 1; i < n; ++i) {
		a[i] = a[i - 1] + q[i];
	}
	for(int i = 0; i < n; ++i) {
		if(a[i] >= 1 && a[i] <= n)
		vis[a[i]]++;
	}
	for(int i = 1; i <= n; ++i) if(vis[i] != 1) return cout << -1 << endl,0;
	for(int i = 0; i < n; ++i) {
		cout << a[i] << ' ';
	}
    return 0;
}
