/*************************************************************************
    > File Name: C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com
    > Created Time: 2019年04月16日 星期二 23时24分17秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
int food[7] = {1,1,2,3,1,3,2};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
    int a[4] = {0}, b[4] = {0}, c[4] = {0};
    cin >> b[1] >> b[2] >> b[3];
	int serv = min(b[1] / 3,min(b[2] / 2, b[3] / 2));
	b[1] -= 3 * serv; b[2] -= 2 * serv; b[3] -= 2 * serv;
    int ans = serv * 7;
//	DEBUG(b[1]); DEBUG(b[2]); DEBUG(b[3]);
	pair<int,int> p = make_pair(0,-1);
	for(int s = 0; s < 7; ++s) {
		int cnt = 0;
		for(int i = 1; i <= 3; ++i) a[i] = b[i];
		for(int i = s; ; i = (i + 1) % 7) {
			if(a[food[i]] <= 0) break;
			a[food[i]]--;
			cnt++;
		}
		if(cnt > p.second) {
			p = make_pair(s,cnt);
		}
	}
    cout << ans + p.second << endl;
    return 0;
}

