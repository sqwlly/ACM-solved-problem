/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年10月02日 星期二 19时59分37秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
int a[111][111];

int main()
{
#ifndef ONLINE_JUDGE
//    freopen("input.in","r",stdin);
#endif
	int n,m,p;
	cin>>n>>m>>p;
	if(n % p != 0 && m % p != 0){
		puts("No");
		return 0;
	}
	puts("Yes");
	int num = 0;
	for(int d = 1; d  <= m && m % p == 0; d += p){
		for(int i = 1; i <= n; ++i){
			num++;
			for(int j = d, w = 0; j <= m && w < p; ++j, ++w){
				a[i][j] = num;
			}
		}
	}
	for(int x = 1; x <= n && n % p == 0; x += p){
		for(int j = 1 ; j <= m; ++j){
			num++;
			for(int k = x, w = 0; k <= n && w < p; ++k, ++w){
				a[k][j] = num;
			}
		}
	}
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			printf("%d%c",a[i][j],j == m ? '\n' : ' ');
		}
	}
    return 0;
}
