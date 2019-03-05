/*************************************************************************
    > File Name: L2_017.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月05日 星期二 14时33分49秒
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
	int n, sum = 0, sumA = 0, sumB = 0;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		sum += a[i];
	}
	sort(a, a + n);
	for(int i = 0; i < n / 2; ++i) {
		sumA += a[i];
	}
	sumB = sum - sumA;
	int dif = 0, cnt = n / 2;
	if(n & 1) {
		if(abs(sumA - sumB) > abs(sumA + a[n / 2 + 1] - sumB + a[n / 2] + 1)) {
			cnt = n / 2;
		}else{
			cnt = n / 2 + 1;
		}
		dif = max(abs(sumA - sumB), abs(sumA + a[n / 2 + 1] - (sumB - a[n / 2 + 1])));
	}else{
		dif = abs(sumA - sumB);
	}
	cout << "Outgoing #: " << n - cnt << endl;
	cout << "Introverted #: " << cnt << endl;
	cout << "Diff = " << dif << endl;
    return 0;
}
