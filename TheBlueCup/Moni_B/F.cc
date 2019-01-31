/*************************************************************************
    > File Name: F.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年01月31日 星期四 14时39分49秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
const int N = 1E6+100;
int prime[N];
bool vis[N];
int init()
{
	int k = 0;
	for(int i = 2; i < N; ++i) {
		if(vis[i] == 0) {
			prime[k++] = i;
		}
		for(int j = 2; i * j < N; ++j) {
			if(vis[i * j] == 0)
				vis[i * j] = 1;
		}
	}
	return k;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int t,n;
	int k = init();
	cin >> t;
	while(t--) {
		scanf("%d",&n);
		for(int i = 0; i < k; ++i) {
			if(vis[n - prime[i]] == 0) {
				printf("%d %d\n",prime[i],n - prime[i]);
				break;
			}
		}
	}
    return 0;
}
