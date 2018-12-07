/*************************************************************************
    > File Name: G.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年12月06日 星期四 11时16分05秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
typedef long long LL;

void exgcd(LL a,LL b,LL &x,LL &y, LL &d) 
{
	if(b == 0) {
		x = 1, y = 0;
		d = a;
		return;
	}
	exgcd(b, a % b, y, x, d);
	y -= (a / b) * x;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	LL a,b,x,y,d;
	while(cin >> a >> b)
	{
		exgcd(a,b,x,y,d);
		if(1 % d) {
			cout << "sorry" << endl;
			continue;
		}
		LL k = (y - x) / (a + b);
		x += k * b, y -= k * a;
		if(x < 0) {
			x += b, y -= a;
		}
		cout << x << ' ' << y << endl;
	
	}
    return 0;
}
