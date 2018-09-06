#include<bits/stdc++.h>
using namespace std;
int love(int n)
{
	int ret = 0, s = sqrt(n);
	for(int i = 1; i <= s; ++i)
		if(n % i == 0)
			ret += 2;
	if(s * s == n)
		ret--;
	return ret;
}
int main()
{
    int T,a,b;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&a,&b);
		int f = love(a), u = love(b), c = love(__gcd(a,b)), k = f * u - c*(c-1)/2;
        printf("%d\n",k);
    }
    return 0;
}
