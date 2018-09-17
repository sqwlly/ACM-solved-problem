#include<bits/stdc++.h>

using namespace std;
typedef long long LL;

LL gcd(LL a, LL b){
    return b == 0 ? a : gcd(b, a % b);
}

void ex_gcd(LL a, LL b, LL &x, LL &y){
    if(b == 0){
        x = 1, y = 0; return;
    }
    ex_gcd(b, a % b, y, x);
    y -= (a / b) * x;
}

LL a, b;
int main(){

    cin >> a >> b;
    if(a > b) swap(a, b); 
    LL x, y;
    ex_gcd(a, b, x, y);
    if(x > 0){
        swap(a, b);
        swap(x, y);
    }
	LL k = (y-x)/(a+b);
	x += k*b, y -= k*a;
	if(x > y) 
		y += a, x -= b;
    LL ans;
    LL x2 = x + b;
    ans = a * (x2 - 1) + b * (y - 1);
    cout << ans - 1 << endl;

    return 0;
}
