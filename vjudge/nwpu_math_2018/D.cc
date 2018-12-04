/*************************************************************************
    > File Name: D.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年12月03日 星期一 16时21分35秒
 ************************************************************************/

#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
const int N = 1E7+10, M = N / log(N) + N/10;
int prime[M], k;
bool vis[N];
void init()
{
	for(int i = 2; i < N; ++i) {
		if(vis[i] == 0)
			prime[k++] = i;
		for(int j = 2; j * i < N; ++j) {
			if(vis[i * j] == 0) 
				vis[i * j] = 1;
		}
	}
}

LL solve(LL n)
{
	LL t = n, ans = 1;
	for(int i = 0; i < k && prime[i] <= sqrt(t); ++i) {
		int cnt = 0;
		while(n % prime[i] == 0) {
			cnt++;
			n /= prime[i];
		}
		ans *= (2 * cnt + 1);
	}
	if(n > 1) ans *= (2 * 1 + 1);
	return ans / 2 + 1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	init();
	int T, t = 1;
	cin >> T;
	while(T--) {
		LL n;
		cin >> n;
		LL ans = solve(n);
		cout << "Case "<< t++ << ": " << ans << endl;
	}
    return 0;
}
