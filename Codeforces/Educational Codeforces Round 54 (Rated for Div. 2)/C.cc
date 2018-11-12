/*************************************************************************
    > File Name: C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年11月12日 星期一 23时32分28秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
int d;
long double ans = 0;
bool love(long double x)
{
	if(x * ((long double)d - x) > d) {
		return 1;
	}
	return 0;
	
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int t;
	cin>>t;
	while(t--) {
		cin>>d;
		int f = 0;
		long double l = d - 2, r = d;
		if(d < 4) {
			if(d == 0) {
				printf("Y %.9f %.9f\n",0.0,0.0);
				continue;
			}else{
				printf("N\n");
				continue;
			}
		}
		if(d >= 4)
		while(l < r) {
			long double mid = (l + r) / 2, a = mid, b = d - mid;
			if(fabs(a * b - d) <= 1e-7) {
				ans = mid;
				break;
			}
			if(love(mid))
				l = mid;
			else
				r = mid;
		}
		if(ans){
			printf("Y %.9f %.9f\n",(double)ans,(double)(d-ans));
		}else{
			printf("N\n");
		}
	}
	
    return 0;
}
