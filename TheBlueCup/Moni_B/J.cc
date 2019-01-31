/*************************************************************************
    > File Name: J.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年01月31日 星期四 15时03分05秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
const int N = 5E5 * 2;
int a[N],n;
long long sum[N];
long long solve()
{
	deque<int> dq;
	long long ans = 0;
	for(int i = 1; i <= 2 * n; ++i) {
		while(!dq.empty() && sum[dq.back()] > sum[i - 1])
			dq.pop_back();
		while(!dq.empty() && dq.front() + n < i) //控制子段长度不超过n
			dq.pop_front();
		dq.emplace_back(i - 1);
		ans = max(ans,sum[i] - sum[dq.front()]);
	}
	return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	for(int i = 0; i < n; ++i) {
		a[i + n] = a[i];
	}
	for(int i = 1; i <= 2 * n; ++i)
		sum[i] = sum[i - 1] + a[i];
	cout << solve() << endl;
    return 0;
}
