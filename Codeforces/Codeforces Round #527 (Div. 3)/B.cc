/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年12月18日 星期二 22时48分51秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n, a[200] = {0}, book[200] = {0};
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	sort(a, a + n);
	int sum = 0;
	for(int i = 1; i < n; i += 2) {
		sum += a[i] - a[i - 1];
	}
	cout << sum << endl;
    return 0;
}
