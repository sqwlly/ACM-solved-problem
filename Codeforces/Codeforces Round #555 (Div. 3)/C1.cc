/*************************************************************************
    > File Name: C1.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年04月26日 星期五 23时15分51秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 2e5+10;
int a[N],c[N];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	string ans = "";
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int l = 0, r = n - 1, k = 1;
	while(l <= r) {
		if(a[l] > a[r]) {
			if(a[r] < c[k - 1]) {
				if(a[r] < c[k - 1]){
					if(a[l] < c[k - 1]) {
						break;
					}else{
						a[k++] = a[l];
						l++;
						ans += 'L';
					}
				}else{
					a[k++] = a[r];
					ans += 'R';
					r--;
				}
			}
		}else if(a[l] < a[r]){
			if(a[l] < c[k - 1]) {
				if(a[l] < c[k - 1]){
					if(a[r] < c[k - 1]) {
						break;
					}else{
						a[k++] = a[r];
						r--;
						ans += 'R';
					}
				}else{
					a[k++] = a[l];
					ans += 'L';
					l++;
				}
			}

		}else{
			break;
		}
	}
	cout << ans.size() << endl;
	cout << ans << endl;
    return 0;
}
