/*************************************************************************
    > File Name: I.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年12月11日 星期二 00时51分42秒
 ************************************************************************/

#include<iostream>
#include<cmath>

using namespace std;

void exgcd(int a, int b, int &x, int &y, int &d)
{
	if(b == 0) {
		x = 1, y = 0;
		d = a;
		return;
	}
	exgcd(b, a % b, y, x, d);
	y -= a / b * x;
}

void solve(int a, int b, int d, int &x, int &y)
{
	int g, t;
	exgcd(a,b,x,y,g);
	x *= d / g;
	t = b / g;
	x = (x % t + t) % t; //最小正整数解
	y = abs((a * x - d) / b);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int a,b,c,x1,x2,y1,y2;
	while(cin >> a >> b >> c && (a + b + c)) {
		solve(a,b,c,x1,y1);
		solve(b,a,c,x2,y2);
		if(x1 + y1 < x2 + y2) {
			cout << x1 << ' ' << y1 << endl;
		}else {
			cout << y2 << ' ' << x2 << endl;
		}
	}

    return 0;
}
