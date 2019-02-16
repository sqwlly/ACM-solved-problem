#include<iostream>

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
	LL a,b,x,y,d,p,q,m,n,c,L;
	cin >> p >> q >> m >> n >> L;
	a = m - n, b = L, c = q - p;
	exgcd(a,b,x,y,d);
	if(c % d) {
		cout << "Impossible" << endl;
		return 0;
	}
	//ax + by = 1
	//ax + by = c
	x = x * (c / d);
	y = y * (c / d);
	LL k = (y - x) / (a + b);
	x += k * b, y -= k * a;
	if(x <= 0) x += b, y -= a;
	cout << x << endl;
//	第二种写法
//	LL ans = (x % L + L) % L; cout << ans << endl; 

    return 0;
}



