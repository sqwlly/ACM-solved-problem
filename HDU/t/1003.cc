/*************************************************************************
    > File Name: 1003.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月16日 星期六 14时23分37秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 1e6 + 1e5;

bool vis[N * 10];
int book[N * 10];
bool check(int n)
{
	set<int> s;
	int t = n, sum = 0;
	while(t != 1) {
		sum = 0;
		s.insert(t);
		while(t != 0) {
			sum += (t % 10) * (t % 10);
			t /= 10;
		}
		t = sum;
		if(s.find(t) != s.end()) return 0;
	}

	return 1;
}
int v[150001],cnt;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	for(int i = 1; i < N; ++i) {
		if( check(i)) {
			v[cnt++] = i;
		}
		if(cnt == 150000 - 1) break;
	}
//	DEBUG(cnt);
//	DEBUG(v[cnt - 1]);
	int q,k;
	scanf("%d",&q);
	while(q--) {
		scanf("%d",&k);
		printf("%d\n",v[k - 1]);
	}
    return 0;
}
