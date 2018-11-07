/*************************************************************************
    > File Name: hdu5353.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年11月05日 星期一 17时36分50秒
 ************************************************************************/

#include<bits/stdc++.h>
typedef long long LL;
#define P pair<int,int>
using namespace std;
int a[100100], b[100100], n;
vector< P > ans;
bool solve(int start,int d)
{
	ans.clear();
	memcpy(b,a,sizeof a);
	int f = 0;
	if(b[start] == 2) {
		int s = start, e = (s - d + n) % n;
		b[s]--, b[e]++;
		ans.push_back(P(s,e));
		f = 1;
	}
	for(int i = 0; i < n - f; ++i) {
		int s = (start + i * d + n) % n, e = (start + (1 + i) * d + n) % n;
		int diff = b[s];
		if(diff == 1) {
			ans.push_back(make_pair(s + 1, e + 1));
			b[s]--; b[e]++;
		}else if(diff == -1) {
			ans.push_back(make_pair(e + 1, s + 1));
			b[s]++; b[e]--; 
		}else if(diff == 0){
			continue;
		}else{
			return 0;
		}
	}
	for(int i = 0; i < n; ++i) if(b[i])  return 0;
	printf("YES\n%d\n", (int)ans.size());
	for(int i = 0; i < ans.size(); ++i) {
		printf("%d %d\n",ans[i].first, ans[i].second);
	}
	return 1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int T;
	cin>>T;
	while(T--) {
		scanf("%d",&n);
		LL sum = 0;
		int id = 0;
		for(int i = 0; i < n; ++i) {
			scanf("%d",a+i);
			sum += a[i];
		}
		if(sum % n != 0) {
			puts("NO");
			continue;
		}
		int av = sum / n, f = 1;
		for(int i = 0; i < n; ++i) a[i] -= av;
		for(int i = 0; i < n; ++i) {
			if(abs(a[i]) > 2 || (n == 2 && abs(a[0]) >= 2)) {
				puts("NO");
				f = 0;
				break;
			}
		}
		if(!f) continue;
		for(int i = 0; i < n; ++i) {
			if(a[i] > 0) { id = i; break; }
		}
		int ok = 1;
		if(!solve(id,1)) ok = solve(id,-1);		
		if(ok == 0) puts("NO");
	}
    return 0;
}
