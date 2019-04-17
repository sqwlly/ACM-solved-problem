/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年04月16日 星期二 22时35分18秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
int a[4];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
//	cin >> a >> b >> c >> d;
	for(int i = 0; i < 4; ++i) {
		cin >> a[i];
	}
	sort(a, a + 4);
	for(int i = 0; i < 3; ++i) {
		cout << a[3] - a[i] << ' ';
	}
    return 0;
}
