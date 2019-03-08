/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月07日 星期四 23时28分01秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 2E5+10;
int a[N];
bool vis[N];
int book[102];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n, k;
	cin >> n >> k;
	int sum = 0, p = 0;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		a[i] %= k;
	//	cout << a[i] << endl;
		if(a[i] == 0) p++;
		book[a[i]]++;
	}
	int cnt = 0;
	for(int i = 1; i <= 100; ++i) {
		if(book[i] && book[k - i]) {
			int m1 = min(book[i],book[k - i]);
			if(i == k - i) cnt += m1 / 2 * 2;
			else cnt += m1 * 2;
			if(i != k - i) {
				book[i] -= m1; book[k - i] -= m1;
			}else{
				book[i] -= m1 / 2 * 2;
			}
		}
	}
	int ans = cnt + p / 2 * 2;
	cout << ans << endl;
    return 0;
}

