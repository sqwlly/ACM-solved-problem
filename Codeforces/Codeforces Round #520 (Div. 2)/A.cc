/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年11月14日 星期三 23时40分37秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n, a[1111] = {0};
	cin>>n;
	for(int i = 0; i < n; ++i)
		cin>>a[i];
	int cnt = 0, tot = 0;
	for(int i = 0; i < n; ++i) {
		if(i == n - 1 && a[i] - 1 != a[i - 1]) {
			tot++;
			break;
		}
		if(a[i] != a[i + 1] - 1) {
			tot++;
		}
	}
	if(tot == n) {
		return cout<<0<<endl,0;
	}
	int ans = 0, d = 0;
	if(a[0] == 1) {
		cnt = 1;
		for(int i = 1; i < n; ++i) {
			d = i;
			if(a[i] - 1 == a[i - 1]) {
				cnt++;
			}else{
			//	d = i;
				break;
			}
		}
//		cout<<cnt - 1<<endl;
		if(cnt > 1)
			ans = max(ans,cnt - 1);
		cnt = 1;
	}
	int k = n;
	if(a[n - 1] == 1000) {
		cnt = 1;
		for(int i = n - 1; i >= d; --i) {
			k = i;
			if(a[i] - 1 == a[i - 1]) {
				cnt++;
			}else{
				k = i;
				break;
			}
		}
//		cout<<cnt - 1<<endl;
		if(cnt > 1)
			ans = max(ans,cnt - 1);
		cnt = 1;
	}
	cnt = 1;
	for(int i = d; i < k; ++i) {
		if(a[i] == a[i + 1] - 1) {
			cnt++;
		}else{
			ans = max(ans, cnt - 2);
			cnt = 1;
		}
	}
	if(cnt > 2) {
	//	cout<<cnt-2<<endl;
		ans = max(ans, cnt - 2);
	}
	cout<<ans<<endl;
    return 0;
}
