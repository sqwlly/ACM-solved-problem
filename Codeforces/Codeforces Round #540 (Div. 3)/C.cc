/*************************************************************************
    > File Name: C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年02月19日 星期二 23时11分32秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
int a[21][21],cnt[1010],x[410];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n;
	cin >> n;
	for(int i = 0; i < n * n; ++i) {
		cin >> x[i];
		cnt[x[i]]++;
	}
	int w = 0;
	if(n == 1) {
		puts("YES");
		cout << x[0] << endl;
		return 0;
	}
	int o = 0;
	/*
	for(int i = 1; i <= 1000; ++i) {
		if(n % 2 == 0 && cnt[i] != 0 && cnt[i] % 4 != 0) {
			return puts("NO"),0;
		}
		if(n % 2 == 1 && cnt[i] && (cnt[i] % 4 == 1 || cnt[i] % 4 == 3)) {
			o++;
		}
	}
	if(n % 2 == 1 && o == 0) return puts("NO"),0;
	puts("YES");*/
	for(int i = 1; i <= n / 2; ++i) {
		for(int j = 1; j <= n / 2; ++j) {
			bool f = 0;
			for(int k = 1; k <= 1000; ++k) {
				if(cnt[k] >= 4) {
					a[i][j] = a[i][n - j + 1] = a[n - i + 1][j] = a[n - i + 1][n - j + 1] = k;
					cnt[k] -= 4;
					f = 1;
					break;
				}
			}
			if(!f) return puts("NO"),0;
		}
	}
	if(n & 1) {
		for(int d = 1; d <= n / 2; ++d) {
			bool f = 0;
			for(int i = 1; i <= 1000; ++i) {
				if(cnt[i] >= 2) {
					a[n / 2 + 1][d] = a[n / 2 + 1][n - d + 1] = i;
					cnt[i] -= 2;
					f = 1;
					break;
				}
			}
			if(!f) return puts("NO"),0;
			f = 0;
			for(int i = 1; i <= 1000; ++i) {
				if(cnt[i] >= 2) {
					a[d][n / 2 + 1] = a[n - d + 1][n / 2 + 1] = i;
					cnt[i] -= 2;
					f = 1;
					break;
				}
			}
			if(!f) return puts("NO"),0;
		}
		bool f = 0;
		for(int i = 1; i <= 1000; ++i) 
			if(cnt[i]) {  
				f = 1;
				a[n / 2 + 1][n / 2 + 1] = i;
				break;
			}
		if(!f)  return puts("NO"),0;
	}
	puts("YES");
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= n; ++j) {
			cout << a[i][j];
			if(j < n) cout << ' ';
		}
		cout << endl;
	}
    return 0;
}
