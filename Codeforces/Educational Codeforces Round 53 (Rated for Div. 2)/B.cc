/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年10月25日 星期四 22时51分19秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
bool vis[200100];
int a[200100],b[200100];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n;
	cin>>n;
	for(int i = 0; i < n; ++i){
		scanf("%d",&a[i]);
	}
	for(int i = 0; i < n; ++i){
		scanf("%d",&b[i]);
	}
	vector<int> ans;

	int top = 0;
	for(int i = 0; i < n; ++i){
		int cnt = 0;
		if(!vis[b[i]]){
			for(; top < n;){
				if(!vis[a[top]] && a[top] != b[i]){
					vis[a[top]] = 1;
					top++;
					cnt++;
				}else if(a[top] == b[i]){
					cnt++;
					vis[a[top]] = 1;
					top++;
					break;
				}else if(vis[a[top]]){
					break;
				}
			}
		}
		//printf("%d %d\n",i,cnt);
		ans.push_back(cnt);
	}
	for(int i = 0; i < ans.size(); ++i)
		printf("%d%c",ans[i],i==ans.size()-1?'\n':' ');
    return 0;
}
