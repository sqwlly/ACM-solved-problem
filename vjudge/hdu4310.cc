/*************************************************************************
    > File Name: hdu4310.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年10月13日 星期六 18时05分34秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;

struct node{
	int dps,hp;

	bool operator < (const node & u)const{
		if(1.0 * hp / dps == 1.0 * u.hp / u.dps)
			return dps > u.dps;
		return 1.0 * hp / dps < 1.0 * u.hp / u.dps;
	}
}a[21];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n;
	while(cin>>n){
		int sum = 0;
		for(int i = 0; i < n; ++i){
			cin>>a[i].dps>>a[i].hp;
			sum += a[i].dps;
		}
		sort(a,a+n);
		int ret = 0;
		for(int i = 0; i < n; ++i){
			ret += sum * a[i].hp;
			sum -= a[i].dps;
		}
		cout<<ret<<endl;
	}

    return 0;
}
