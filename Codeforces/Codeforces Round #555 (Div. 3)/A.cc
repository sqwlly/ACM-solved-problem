/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年04月26日 星期五 22时34分37秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
typedef long long LL;
map<int,bool> vis;
int f(int x)
{
	
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n, cnt = 1;
	cin >> n;
	while(1) {
		vis[n] = 1;
		n = n + 1;
//		DEBUG(n);
		while(n % 10 == 0) {
			n /= 10;
		}
		if(vis[n]) break;
		cnt++;
	}
	cout << cnt << endl;
    return 0;
}
