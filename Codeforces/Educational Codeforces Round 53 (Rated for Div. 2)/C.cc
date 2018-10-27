/*************************************************************************
    > File Name: C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年10月26日 星期五 23时16分58秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
const int N = 200100;
int U[N],R[N],L[N],D[N];
int n,x,y,sx,sy;
bool ok(int s,int t)
{
	int ret = t - s + 1, tx = sx, ty = sy;
	tx += L[t] - L[s - 1];
	ty += D[t] - D[s - 1];
	tx -= R[t] - R[s - 1];
	ty -= U[t] - U[s - 1];
	if(abs(x - tx) + abs(y - ty) > ret) return 0;
	return (ret - abs(x - tx) - abs(y - ty)) % 2 == 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	string s;
	cin>>n>>s>>x>>y;
	for(int i = 0; i < n; ++i) {
		if(s[i] == 'L') sx--, L[i + 1] = 1;
		if(s[i] == 'R') sx++, R[i + 1] = 1;
		if(s[i] == 'U') sy++, U[i + 1] = 1;
		if(s[i] == 'D') sy--, D[i + 1] = 1;
	}
	if(sx == x && sy == y) return cout<<0<<endl, 0;
	for(int i = 1; i <= n; ++i) {
		L[i] += L[i - 1];
		R[i] += R[i - 1];
		U[i] += U[i - 1];
		D[i] += D[i - 1];
	}
	int ans = n + 1;
	for(int i = 1, f = 0; i <= n; ++i, f = 0){
		int l = i, r = n;
		while(l <= r) {
			int mid = l + (r - l) / 2;
			if(!ok(i,mid)) {
				l = mid + 1;
			}else{
				r = mid - 1;
				f = 1;
			}
		}
		if(f) ans = min(ans,r - i + 2);
	}
	if(ans == n + 1) ans = -1;
	cout<<ans<<endl;
    return 0;
}
