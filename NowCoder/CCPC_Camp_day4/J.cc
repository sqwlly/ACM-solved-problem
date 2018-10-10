/*************************************************************************
    > File Name: J.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年10月04日 星期四 12时11分59秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n,m,x;
	string s,pre;
	vector<int> ans;
	int vis[100000] = {0};
	cin>>n>>m;
	cin>>x>>s;
	pre = s;
	for(int i = 0; i < m - 1; ++i){
		cin>>x>>s;
		if(pre!=s)
			vis[x] = 1;
		pre = s;
	}
	for(int i = 1; i <= n; ++i)
		if(!vis[i])
			ans.push_back(i);
	for(int i = 0; i < ans.size(); ++i)
		printf("%d%c",ans[i],i==ans.size()-1?'\n':' ');
    return 0;
}
