/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年02月16日 星期六 20时11分18秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
int a[100];
int main()
{
	int n,m,k,x;
	cin >> n >> m;
	for(int i = 0; i < n; ++i) {
		cin >> k;
		for(int j = 0; j < k; ++j) {
			cin >> x;
			a[x]++;
		} 
	}
	int cnt = 0;
	for(int i = 1; i <= m; ++i) {
		if(a[i] == n) cnt++;
	}
	cout << cnt << endl;
    return 0;
}
