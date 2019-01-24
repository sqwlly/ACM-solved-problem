/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年01月23日 星期三 23时03分41秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
int d[200];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> d[i];
	}
	sort(d,d + n);
//	int t = 1, k = 1;
	long long x = *max_element(d,d+n);
	for(int i = 1; i <= x; ++i) {
		if(x % i == 0) {
			for(int j = 0; j < n; ++j) {
				if(i == d[j]) {
					d[j] = -1;
					break;
				}
			}
		}
	}
	long long y = 1;
	int t1 = *max_element(d,d+n);



	//1 1 2 2 4 4 5 8 10 20
	//1 2 4 8 
	//1 2 4 5 10 20
	cout << x << ' ' <<t1 << endl;
    return 0;
}
