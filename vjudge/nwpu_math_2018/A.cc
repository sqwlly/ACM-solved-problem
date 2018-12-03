/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年12月02日 星期日 15时50分26秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
const int N = 1e7+10, tot = N/log(N)+ 100000;
int prime[tot];
bool vis[N];

int init()
{
	int k = 0;
	for(int i = 2; i < N; ++i) {
		if(vis[i] == 0) prime[k++] = i;
		for(int j = 2; j * i < N; ++j) {
			if(vis[i * j] == 0)
				vis[i * j] = 1;
		}
	}
	return k;
}

bool isPrime(int n)
{
	int t = sqrt(n);
	for(int i = 2; i <= t; ++i) 
		if(n % i == 0) return 0;
	return n != 1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int k = init();
	int T, n, t = 1;
	cin >> T;
	while(T--) {
		scanf("%d",&n);
		int cnt = 0;
		for(int i = 0; i < k; ++i) {
			if(prime[i] > n / 2) break;
			if(vis[n - prime[i]] == 0) {
				cnt++;
			}
		}
		printf("Case %d: %d\n",t++,cnt);
	}
    return 0;
}
