/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年01月31日 星期四 20时46分13秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
const int N = 3E5+10;
long long a[N];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		scanf("%lld",&a[i]);
	}
	sort(a,a+n);
	long long sum = 0;
	for(int i = 0; i < n / 2; ++i) {
		sum += (a[i] + a[n - i - 1]) * (a[i] + a[n - i - 1]);
	}
	cout << sum << endl;
    return 0;
}
