/*************************************************************************
    > File Name: I.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月09日 星期六 21时52分46秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 1E5+10;
int sum[N],n;

void update(int x,int y)
{
	while(x < n) {
		sum[x] += y;
		x += x & (-x);
	}
}

int query(int x)
{
	int ret = 0;
	while(x > 0) {
		ret += sum[x];
		x -= x & (-x);
	}
	return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int m,c,l,r;
	cin >> n >> m;
	for(int i = 0; i < m; ++i) {
		cin >> c >> l >> r;
		if(c == 1) {
			for(int j = l; j <= n; j += l) update(j, r);
		}else{
			cout << query(r) - query(l - 1) << endl;
		}
	}
    return 0;
}
