/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com
    > Created Time: 2019年05月11日 星期六 19时00分35秒
 ************************************************************************/
 
#include<bits/stdc++.h>
 
using namespace std;
const int N = 1E5+10;
int a[N];
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	if(n & 1) cout << 1 << endl;
	else cout << 2 << endl;
    return 0;
}
