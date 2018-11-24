/*************************************************************************
    > File Name: C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年11月24日 星期六 16时20分44秒
 ************************************************************************/

#include<bits/stdc++.h>
typedef long long LL;
using namespace std;

struct rec{
	int x1,y1,x2,y2;
	rec() {}
	rec(int a,int b,int c,int d) { x1 = a; y1 = b; x2 = c; y2 = d;}
};
int n,m;
bool comb(rec a,rec b)
{
	if(a.x1 == b.x1 && a.y1 == b.y1) return 1;
	if(abs((a.x1+a.x2)/2-(b.x1+b.x2)/2)<((a.x2+b.x2-a.x1-b.x1)/2) && abs((a.y1+a.y2)/2-(b.y1+b.y2)/2)<((a.y2+b.y2-a.y1-b.y1)/2))
	return true;
	return false;
}

void color(rec a,LL &sum_b,LL &sum_w,int d)
{
	LL a_m = a.x2 - a.x1, a_n = a.y2 - a.y1;
	if(a_m <= 0 || a_n <= 0) return;
	if(a.x1 % 2 == 1 && a.y1 % 2 == 1) {
		sum_b -= (a_n * a_m / 2) * d;
		sum_w += (a_n * a_m / 2) * d;
	}else{
		sum_b -= (a_n * a_m / 2 + 1) * d;
		sum_w += (a_n * a_m / 2 + 1) * d;
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int T;
	cin>>T;
	while(T--) {
		rec a,b;
		cin>>n>>m;
		cin>>a.x1>>a.y1>>a.x2>>a.y2;
		cin>>b.x1>>b.y1>>b.x2>>b.y2;
		LL sum_w = 0, sum_b = 0;
		if(n & 1) {
			if(m & 1) {
				sum_w = 1LL * n * m / 2 + 1;
				sum_b = 1LL * n * m / 2;
			}else{
				sum_w = 1LL * n * m / 2;
				sum_b = 1LL * n * m / 2;
			}
		}else{
			if(m & 1) {
				sum_w = 1LL * n * m / 2;
				sum_b = 1LL * n * m / 2;
			}else{
				sum_w = 1LL * n * m / 2;
				sum_b = 1LL * n * m / 2;
			}
		}
		if(comb(a,b) == 0) {
			color(a,sum_b,sum_w,1);
			color(b,sum_b,sum_w,-1);
		}else{
			rec t1,t2;
			if(a.x1 < b.x1 && a.y1 < b.y1) {
				t1 = rec{a.x1,a.y1,b.x1,a.y2};
				t2 = rec{b.x1,a.y1,a.x2,b.y1};
			}else{
				t1 = rec{a.x1,a.y1,b.x1,a.y2};
				t2 = rec{b.x1,b.y2,a.x2,a.y2};
			}
			color(t1,sum_b,sum_w,1);
			color(t2,sum_b,sum_w,1);
			color(b,sum_b,sum_w,-1);
			
		}
		cout << sum_w <<' '<< sum_b << endl;
	}
    return 0;
}
