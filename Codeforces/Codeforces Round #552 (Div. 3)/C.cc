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
	for(int i = 1; i <= 3; ++i) a[i] = b[i];
    int ret = 0, ans = 0;
	pair<int,int> p;
	for(int s = 0; s < 7; ++s) {
		int cnt = 0;
		for(int i = s; ; i = (i + 1) % 7) {
			if(a[food[i]] <= 0) break;
			a[food[i]]--;
			cnt++;
			if(cnt >= 7) break;
		}
		if(cnt > p.second) {
			p = make_pair(s,cnt);
		}
	}

    for(int s = 0; s < 7; ++s) {
        ret = 0;
		for(int i = 1; i <= 3; ++i) a[i] = b[i];
		int cur = s;
		c[1] = c[2] = c[3] = 0;
		for(int i = 0; i < 7; ++i) {
			c[food[cur]]++;
		}
		
        for(int i = s; 1; i = (i + 1) % 7) {
          //  DEBUG(i);
            assert(food[i] >= 1);
            if(a[food[i]] <= 0) break;
            a[food[i]]--;
            ret++;
        }
        ans = max(ret, ans);
    }
    cout << ans << endl;
    return 0;
}

