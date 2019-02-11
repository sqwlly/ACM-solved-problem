/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年02月10日 星期日 22时02分06秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int x,y,z,a,b,c;
	cin >> x >> y >> z >> a >> b >> c;
	int f = 1;
	if(x > a) {
		f = 0;
	}else{
		a -= x;
	}
	if(a + b < y) f = 0;
	else {
		int ret = a + b + c - y;
		if(ret < z) f = 0;
	}
	puts(f?"YES":"NO");
    return 0;
}
