/*************************************************************************
    > File Name: E.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年12月05日 星期三 10时16分51秒
 ************************************************************************/

#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
const int N = 1E6+100, M = N / log(N) + N / 10;
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

LL count1(LL n)
{
	LL ans = 1;
	for(LL i = 0; i < k && prime[i]*prime[i] <= n; ++i) {
		LL cnt = 0;
		while(n % prime[i] == 0) {
			n /= prime[i];
			cnt++;
		}
		ans *= (cnt + 1);
	}
	if(n > 1) ans *= (1 + 1);

	return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	init();
	int T, w = 1;
	LL a,b;
	cin >> T;
	while(T--) {
		cin >> a >> b;
		LL ret = count1(a) / 2;
		for(LL i = 1; i < b && b * b <= a; ++i) {
			if(a % i == 0) {
				ret--;
			}
		}
		if(b * b >= a) ret = 0;
		cout << "Case "<< w++ << ": " << ret << endl;
	}

    return 0;
}
