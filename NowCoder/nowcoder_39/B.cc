/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年02月08日 星期五 19时16分16秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
const int N = 1E5+10;
int w[N],d[N],ans[N],l[N],r[N],cnt;

void dfs(int rt)
{
	if(!rt) return;
	dfs(l[rt]);
	dfs(r[rt]);
	d[++cnt] = w[rt] * -1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		scanf("%d", w + i);
	}
	for(int i = 1; i <= n; ++i) {
		scanf("%d%d",l + i, r + i);
	}
	dfs(1);
	int len = 0;
	for(int i = 1; i <= n; ++i) {
		int t = lower_bound(ans + 1, ans + len + 1,d[i]) - ans;
		ans[t] = d[i], len = max(t, len);
	}
	cout << len << endl;
    return 0;
}
