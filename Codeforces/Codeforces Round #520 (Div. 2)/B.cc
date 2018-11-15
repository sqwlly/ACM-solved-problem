/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年11月15日 星期四 00时53分32秒
 ************************************************************************/

#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
const int N = 1001000;
bool vis[N];
int prime[N];
LL sqr[N], n;
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
/*
bool isSqr(LL n)
{
	long double t = sqrt(n);
	return t == floor(t);
}
*/
int main()
{
#ifndef ONLINE_JUDGE
   // freopen("input.in","r",stdin);
#endif
	int k = init();
	cin>>n;
	if(n == 1) {
		return cout<<"1 0"<<endl,0;
	}
	int cnt = 0;
	map<int,int> p;
	for(int i = 0; i < k && n > 1; ++i) {
		if(n % prime[i] == 0){
			int cnt = 0;
			while(n % prime[i] == 0) {
				n /= prime[i];
				cnt++;
			}
			//cout<<prime[i]<<' '<<cnt<<endl;
			p.insert({prime[i],cnt});
		}
	}
	LL ans = 1; int max_E = 0;
	for(auto & t : p) {
		ans *= t.first;
		max_E = max(max_E,t.second);
	}
	for(auto & t : p) {
		if(max_E != t.second) {
			cnt = 1; break;
		}
	}
	if((1<<(int)log2(max_E)) != max_E && cnt != 1) cnt++;
//	cout<<(log2(max_E))<<endl;
	cnt += ceil(log2(max_E));
	cout<<ans<<' '<<cnt;
    return 0;
}
