/*************************************************************************
    > File Name: hdu5821.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年10月18日 星期四 20时34分50秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
pair<int,int> a[1011];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int T,x,l,r,n,m;
	cin>>T;
	while(T--){
		cin>>n>>m;
		for(int i = 1; i <= n; ++i){
			cin>>a[i].second;
			a[i].first = 0;
		}
		for(int i = 1; i <= n; ++i){
			cin>>x;
			for(int j = 1; j <= n; ++j){
				if(!a[j].first && a[j].second == x){
					a[j].first = i;
					break;
				}
			}
		}
		for(int i = 0; i < m; ++i){
			cin>>l>>r;
			sort(a + l, a + r + 1);
		}
		int f = 0;
		for(int i = 1; i <= n; ++i){
			if(a[i].first != i) f = 1;
		}
		puts(f?"No":"Yes");
	}

    return 0;
}
