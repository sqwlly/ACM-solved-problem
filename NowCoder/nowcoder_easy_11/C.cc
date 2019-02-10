/*************************************************************************
    > File Name: C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年02月09日 星期六 19时08分16秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
const int N = 1E5+10;
int R[N],C[N];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n,m,T,k,x;
	cin >> n >> m >> T;
	for(int i = 1; i <= T; ++i) {
		scanf("%d%d",&k,&x);
		if(k == 1) {
			R[x] = max(R[x],i);
		}else{
			C[x] = max(C[x],i);
		}
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			printf("%d%c",max(R[i],C[j]), j == m ?'\n' :' ');
		}
	}
    return 0;
}
