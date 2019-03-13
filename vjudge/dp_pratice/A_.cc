/*************************************************************************
    > File Name: ../../vjudge/dp_pratice/A_.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月13日 星期三 14时50分05秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,x;
	while(cin >> n) {
		int cnt = 0, ans = -1;
		for(int i = 0; i < n; ++i) {
			cin >> x;
			if(cnt == 0) {
				ans = x;
				cnt++;
			}else{
				if(ans == x) cnt++;
				else cnt--;
			}
		}
		cout << ans << endl;
	}
    return 0;
}
