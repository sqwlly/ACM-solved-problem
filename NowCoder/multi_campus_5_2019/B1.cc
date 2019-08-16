#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=1e4,S=30000001;
char s[S];
LL pi[N],k[N],P;
inline LL gcd(register LL n,register LL m){while(m^=n^=m^=n%=m); return n;}
inline LL lcm(register LL n,register LL m){return n/gcd(n,m)*m;}
struct matrix
{
    LL a[4][4];
    matrix(){memset(a,0,sizeof(a));}
    matrix operator*(matrix x)
    {
        matrix s;
        for(register int i=1;i<=3;i++) for(register int j=1;j<=3;j++) for(register int k=1;k<= 3;k++) s.a[i][j]=(s.a[i][j]+a[i][k]*x.a[k][j])%P;
        return s;
    }
    matrix operator^(register LL k)
    {
        matrix s=*this,e;
        e.a[1][1]=e.a[2][2]=e.a[3][3]= 1;
    for(;k;k>>=1,s=s*s) if(k&1) e=e*s; 
        return e;
    }
};
inline LL power(register LL n,LL A,LL B,LL x0,LL x1)
{
    matrix a,ans;
	a.a[1][1] = A; a.a[1][2] = B; a.a[2][1] = a.a[1][3] = a.a[3][3] =1; a.a[2][2] = 0;
    ans=a^(n);
	return ans.a[2][1] % P;
//    return (ans.a[1][1] * x1  + ans.a[1][2]  * x0 );
    //return (ans.a[1][1] % P * x1 % P + ans.a[1][2] %P * x0 % P) % P;
}
inline LL Get(register LL p)
{
    register int s=sqrt(p),tot=0;
    for(register int i=2;i<=s;++i)
    if(!(p%i))
    {
        pi[++tot]=i,k[tot]=1;
        while(!(p%i)) p/=i,k[tot]*=i;
    }
    for(register int i=1;i<=tot;++i) k[i]/=pi[i];
    if(p!=1) k[++tot]=1,pi[tot]=p;
    for(register int i=1;i<=tot;++i)
        if(pi[i]==2) k[i]*=3;
        else if(pi[i]==3) k[i]*=5;
        else if(pi[i]==5) k[i]*=20;
        else if(pi[i]%5==1||pi[i]%5==4) k[i]*=pi[i]-1;
        else k[i]*=(pi[i]+1)<<1;
    register LL ans=k[1];
    for(register int i=2;i<=tot;++i) ans=lcm(ans,k[i]);
    return ans;
}
int main()
{
    register int len;
    register LL m,n=0;
	LL x0,x1,A,B;
    scanf("%lld %lld %lld %lld %s%lld",&x0,&x1,&A,&B,s+1,&P),len=strlen(s+1);
    if(P==1) return cout<<0,0;
    m=Get(P);
    for(register int i=1;i<=len;++i) n=((n<<3)+(n<<1)+(s[i]^48))%m;
    if(!n) return cout<<0,0;
    if(n==1) return cout<<x0,0;
    return cout<<power(n,A,B,x0,x1),0;    
}
