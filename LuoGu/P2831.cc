/*************************************************************************
    > File Name: P2831.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年09月24日 星期一 10时32分40秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
const double eps = 1e-6;

struct pig{
	double x,y;
}d[20];

int dp[1<<20],equation[200],n,m,cnt;

void love(double &a,double &b,double x1,double x2,double y1,double y2)
{
	a = (y2 - y1 * x2 / x1) / (x2 * x2 - x1 * x2);
	b = (y1 - a * x1 * x1) / x1;
}

bool more(double a,double b,double x,double y)
{
	double ret_y = a * x * x + b * x;
	return fabs(ret_y - y) <= eps;
}

void prepare()
{
	double a,b;
	for(int i = 0; i < n; ++i){
		equation[cnt++] =  (1<<i); 
		for(int j = i+1, cur = 0; j < n; ++j){
			if(cur >> j & 1) continue;
			love(a,b,d[i].x,d[j].x,d[i].y,d[j].y); //解出a和b
			if(a >= 0) continue;
			equation[cnt] = 1<<i;
			for(int k = j; k < n; ++k){
				if(more(a,b,d[k].x,d[k].y)){ //满足y = a * x^2 + b * x
					cur |= 1<<k;
					equation[cnt] |= 1<<k;
				}
			}
			cnt++;
		}
	}
}

void solve()
{
	memset(dp,0x3f,sizeof dp);
	cin >> n >> m;
	for(int i = 0; i < n; ++i){
		cin >> d[i].x >> d[i].y;
	}
	cnt = 0;
	prepare();
	dp[0] = 0;
	for(int i = 0; i < (1<<n); ++i){
		for(int j = 0; j < cnt; ++j){
			dp[i|equation[j]] = min(dp[i|equation[j]],dp[i]+1);
		}
	}
	cout<<dp[(1<<n)-1]<<endl;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int T;
	cin >> T;
	while(T--) solve();
	
    return 0;
}
