/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年04月16日 星期二 22时41分46秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;

int a[123],b[123],n;

bool check(int d,int i)
{
	for(int j = 1; j <= n; ++j) {
		b[j] = a[j];
	}
	int ok = 1;
	b[1] = d;
	for(int j = 2; j <= n; ++j) {
		int x = b[j] + i;
		int y = b[j] - i;
		int z = b[j];
		if(x != b[j - 1] && y != b[j - 1] && z != b[j - 1]) {
			ok = 0;
			break;
		}
	}
	return ok;
}

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
	}
	int ret = -1;
	sort(a + 1, a + n + 1);
	for(int i = 0; i <= 1000; ++i) {
		int ok = 0;
		if(check(b[1] + i,i) || check(b[1] - i,i) || check(b[1],0)) {
			ok = 1;
		}
		if(ok) {
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
    return 0;
}
