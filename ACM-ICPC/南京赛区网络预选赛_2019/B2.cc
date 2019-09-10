#include<bits/stdc++.h>
#define Mod(a,b) a<b?a:a%b+b						//重定义取模，按照欧拉定理的条件
#define LL long long
#define N 100010
using namespace std;
 
LL n,q,mod,a[N];
map<LL,LL> mp;
 
LL qpow(LL x,LL n,LL mod)
{
    LL res=1;
    while(n)
    {
        if (n&1) res=Mod(res*x,mod),n--;
        x=Mod(x*x,mod); n>>=1;
    }
    return res;
}
 
LL phi(LL k)
{
    LL i,s=k,x=k;
    if (mp.count(k)) return mp[x];					//记忆化存储
    for(i = 2;i * i <= k; i++)
    {
        if(k % i == 0) s = s / i * (i - 1);
        while(k % i == 0) k /= i;
    }
    if(k > 1) s = s / k * (k - 1);
    mp[x]=s; return s;
}
 
LL solve(LL l,LL r,LL mod)
{
    if (l==r||mod==1) return Mod(a[l],mod);					//如果到右端点或者φ值等于1，那么直接返回当前数字
    return qpow(a[l],solve(l+1,r,phi(mod)),mod);			//否则指数为[l+1,r]区间的结果
}
 
int main()
{
	long long w = 0;
    scanf("%lld%lld%lld",&w,&n,&mod);
    for(int i=1;i<=n;i++) a[i] =w;
	printf("%lld\n",solve(1,n,mod) % mod);
    return 0;
}
 
