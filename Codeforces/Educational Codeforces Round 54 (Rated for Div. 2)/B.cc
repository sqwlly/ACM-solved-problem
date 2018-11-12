/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年11月12日 星期一 22时55分16秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
const int N = 100100;
int prime[N];
bool vis[N];
int init()
{
	int k = 0;
	for(int i = 2; i < N; ++i) {
		if(vis[i] == 0) {
			prime[k++] = i;
		}
		for(int j = 2; j * i < N; ++j) {
			if(vis[i * j] == 0) {
				vis[i * j] = 1;
			}
		}
	}
	return k;
}
bool isPrime(long long n)
{
	for(int i = 2; 1LL * i * i <= n; ++i) {
		if(n % i == 0) return 0;
	}
	return 1;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	long long n;
	int cnt = init();
	long long ans = 0;
	cin>>n;
	if(isPrime(n)) {
		cout<<1<<endl;
		return 0;
	}
	if(n % 2 == 0) {
		cout<<n / 2<<endl;
		return 0;
	}
		for(int i = 0; i < cnt; ++i) {
			while(n % prime[i] == 0) {
				if(n - prime[i] >= 0) 
				n -= prime[i];
				ans++; 
				if(n % 2 == 0) {
					ans += n / 2;
					n = 0;
					break;
				}
				//cout<<prime[i]<<endl;
				if(n == 0) break;
			}
			if(n == 0) break;
		}
	cout<< ans <<endl;
    return 0;
}
