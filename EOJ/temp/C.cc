/*************************************************************************
    > File Name: C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年11月16日 星期五 20时49分35秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
struct node{
	LL x,y;
};

LL gcd(LL a,LL b)
{
	if(a % b == 0) {
		return b;
	}
	return gcd(b, a % b);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	node a,b;	
	cin>>a.x>>a.y>>b.x>>b.y;
	if(a.x == b.x && a.y == b.y) {
		if((a.x + b.x) % 2 != 0 || (a.y + b.y) % 2 != 0) {
			puts("NO");
		}else{
			cout<<(a.x + b.x) / 2<<' '<<(a.y + b.y) / 2<<endl;		
		}
	}else{
		node mid = {(a.x + b.x) / 2,(a.y + b.y) / 2};
		node t = a;
		if(a.x > b.x) {
			t.x = b.x;
			t.y = b.y;
		}
		node ans;
		node remote = {t.x, t.y + b.x - t.x};
		LL m = -t.y + b.y + 2 * t.x - 2 * b.x;
		LL n = b.x - t.x;
		LL _gcd = gcd(m,n);
		LL tmpM = m / _gcd;
		LL tmpN = n / _gcd;
		LL p = floor((mid.x - t.x) / n);
		LL q = floor((mid.y - t.y - b.x + t.x) / m);
		if(p > q) {
			p = q;
		}
		if(p == 0) {
			puts("NO");
			return 0;
		}
		ans.x = t.x + p * tmpN;
		ans.y = t.y + b.x - t.x + p * tmpM;
	//	long double k = (long double) m / n;
		//long double k = (t.y - remote.y) / (t.x - remote.x);
	//	LL cnt = max((long double)(mid.x - t.x) / (b.x - t.x),(long double)(t.y + b.x - t.x - b.x) / (-t.y + b.y + 2 * t.x - 2 * b.x));
	//	node ans = {remote.x - n * cnt, remote.y - m * cnt};
		cout<<ans.x<<' '<<ans.y<<endl;
	}
    return 0;
}
