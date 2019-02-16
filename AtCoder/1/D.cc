/*************************************************************************
    > File Name: D.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年02月16日 星期六 20时56分52秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
int a[10], num[10] = {0,2,5,5,4,5,6,3,7,6};
bool cmp(int u,int v)
{
	if(num[u] == num[v]) return u > v;
	return num[u] < num[v];
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n,m;
	cin >> n >> m;
	for(int i = 0; i < m; ++i) 
		cin >> a[i];
	sort(a, a + m, cmp);
	vector<int> v;
	int i = 0;
	while(n > 0 && i < m) {
		int cnt = n / num[a[i]], ret = n % num[a[i]], k = 0, t = 0;
		for(int j = i + 1; j < m; ++j) {
			if(ret % num[a[j]] == 0) {
				k = ret / num[a[j]];
				t = a[j];
				break;
			}
		}
		if(k == 0 && cnt) {
		//	ret += num[a[i]];
			cnt--;
		}
		DEBUG(cnt);
		DEBUG(ret);
		DEBUG(n);
		for(int d = 0; d < cnt; ++d) {
			v.push_back(a[i]);
		}
		n -= num[a[i]] * cnt;
		if(k >= 1) {
			for(int d = 0; d < k; ++d) v.push_back(t);
			n -= num[t] * k;
		}
		i++;
	}
	for(int j = 0; j < v.size(); ++j) {
		cout << v[j];
	}
    return 0;
}
