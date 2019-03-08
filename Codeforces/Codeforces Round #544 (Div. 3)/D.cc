/*************************************************************************
    > File Name: D.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月08日 星期五 12时07分05秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 2E5+10;
map<long double,int> cnt;
int a[N],b[N];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) cin >> a[i];
	for(int i = 0; i < n; ++i) cin >> b[i];
	int k = 0;
	for(int i = 0; i < n; ++i) {
		if(a[i] == b[i] && a[i] == 0) k++;
		if(a[i] == 0) continue;
		cnt[(long double) b[i] / a[i]]++;
	}
	int max1 = 0;
	for(auto i : cnt) {
		max1 = max(max1, i.second);
	}
	cout << max1 + k << endl;
    return 0;
}
