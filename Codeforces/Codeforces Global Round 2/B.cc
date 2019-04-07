/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年04月06日 星期六 20时16分20秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 1024;
int a[N], preMax[N];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,h;
	cin >> n >> h;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		preMax[i] = max(preMax[i], a[i]);
	}
	int ret = 0;
	for(int k = 1; k <= n; ++k) {
		vector<int> v;
		for(int i = 0; i < k; ++i) {
			v.push_back(a[i]);
		}
		sort(v.begin(), v.end(),greater<int>());
		int curH = 0, ok = 1;
		for(int i = 0; i < k; i += 2) {
			if(curH + v[i] > h) {
				ok = 0;
				break;
			}else{
				curH += v[i];
			}
		}
		if(ok) {
			ret = max(ret, k);
		}
	}
	cout << ret << endl;
    return 0;
}
