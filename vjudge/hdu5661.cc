/*************************************************************************
    > File Name: hdu5661.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年10月14日 星期日 10时55分03秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
typedef long long LL;

LL a,b,c,d;

bool ok(LL x,LL y,int i)
{
	LL t = (1LL << i) - 1;
	LL x1 = x + t, y1 = y + t;
	if(x > b || x1 < a || y > d || y1 < c) return 0;
	return 1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int T;
	cin>>T;
	while(T--){
		cin>>a>>b>>c>>d;
		LL x = 0, y = 0;
		for(int i = 62; i >= 0; --i){
			LL t = (1LL << i);
			if(ok(x + t, y, i)){
				x += t;
			}else if(ok(x, y + t, i)){
				y += t;
			}else if(ok(x + t, y + t, i)){
				x += t;
				y += t;
			}
		}
		cout<<(x ^ y)<<endl;
	}
    return 0;
}
