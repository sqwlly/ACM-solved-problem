/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年11月10日 星期六 22时19分01秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
int a[10010],b[10010];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n,s;
	cin>>n>>s;
	for(int i = 1; i <= n; ++i) {
		cin>>a[i];
	}
	for(int i = 1; i <= n; ++i) {
		cin>>b[i];
	}
	if(!a[1] || (!a[s] &&!b[s])) return puts("NO"),0;
	if(a[s] == 1) {
		puts("YES");
		return 0;
	}
		for(int i = s; i <= n; ++i) {
			if(a[i] == 1) {
				for(int j = n; j >= s; --j) {
					if(b[j] == 1 && b[s]) {
						puts("YES");
						return 0;
					}
				}
			}
		}
		puts("NO");
	}
	return 0;
}
