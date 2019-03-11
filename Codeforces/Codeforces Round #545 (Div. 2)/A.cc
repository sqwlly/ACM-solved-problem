/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月08日 星期五 16时15分07秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 100000+10;
int a[N],b[3];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) cin >> a[i];
	
	int MAXL = 0;
	for(int i = 0; i < n; ++i) {
		if(a[i] != a[i - 1]) {
			b[a[i]] = 1;
		}else{
			b[a[i]]++;
		}
		MAXL = max(MAXL,min(b[1],b[2]));
	}
	cout << MAXL * 2 << endl;
    return 0;
}
