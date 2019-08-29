#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll read(){char c=getchar();ll x=0;int f=1;
while(c<'0'||c>'9'){if(c==-1)f=-1;c=getchar();}
while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-48;c=getchar();}x*=f;return x;}
ll pow(ll a,ll n,ll mod){ll ans=1;while(n){if(n&1)ans=ans*a%mod;a=a*a%mod;n>>=1;}return ans;}
int num[200005],cnt;
struct asddddd{int v,next,w;}e[200005];
void add(int u,int v,int w){e[cnt].v=v;e[cnt].w=w;e[cnt].next=num[u];num[u]=cnt++;}
double cul(double a,double b,double c,double d,double e)
{
    return a*b*sqrt(1-pow((a*a+b*b-e*e)/2/a/b,2))+c*d*sqrt(1-pow((c*c+d*d-e*e)/2/c/d,2));
}
int main()
{    //cout<<pow(5913,1.0/3);
    double s[4];
    for(int i=0;i<4;i++)cin>>s[i];
    double ans=0;
    for(int i=0;i<4;i++)
    {
        for(int j=i+1;j<4;j++)
        {
            double a=s[i],b=s[j],c,d;
            if(j-i==1)c=s[(j+1)%4],d=s[(j+2)%4];
            else if(j-i==2)c=s[(i+1)%4],d=s[(j+1)%4];
            else c=s[(i+1)%4],d=s[(i+2)%4];
            double e=max(fabs(a-b),fabs(c-d)),r=min(a+b,c+d);
            while(e<=r)
            {
                ans=max(ans,cul(a,b,c,d,e)/2);
                e+=0.001;
            }
        }
    }
    printf("%.7f",ans);
}
