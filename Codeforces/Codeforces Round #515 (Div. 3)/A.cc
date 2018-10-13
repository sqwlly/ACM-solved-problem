/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年10月12日 星期五 22时39分18秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int T;
	cin>>T;
	while(T--){
		int L,v,l,r;
		scanf("%d%d%d%d",&L,&v,&l,&r);
		int cnt = L / v;
		//cout<<cnt<<endl;
		//cout<<l/v<<endl;
		int l_c = r / v - l / v;
		if(l % v == 0)
			l_c++;
		//if(l % v == 0)
		//	l_c++;
		//l_c += (r - l / v * v) / v;
		printf("%d\n",cnt - l_c);
	}
    return 0;
}
