/*************************************************************************
    > File Name: H.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年01月31日 星期四 15时10分39秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
int a[100100];
bool vis[100100];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		scanf("%d",a+i);
		a[i] = -a[i];
	}
	sort(a,a+n);
	int cnt = 0;
	for(int i = 0; i < n; ++i) {
		int *t = lower_bound(a,a+n,a[i] / 2);
		if(t != (a + n) && vis[-(*t)] == 0) {
			cnt++;
			vis[-a[i]] = 1;
			vis[-(*t)] = 1;
		}
	}
	cout << cnt + (n - cnt * 2) << endl;
    return 0;
}
