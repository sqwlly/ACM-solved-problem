#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll read(){char c=getchar();ll x=0;int f=1;
while(c<'0'||c>'9'){if(c==-1)f=f-1;c=getchar();}
while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-48;c=getchar();}
x*=f;return x;}
ll pow(ll a,ll n,ll mod){ll ans=1;while(n){if(n&1)ans=ans*a%mod;a=a*a%mod;n>>=1;}return ans;}
ll x[100005],y[100005];
int main()
{
   int n=read();
    n=n*2;
   for(int i=0;i<n;i++)
   {
       cin>>x[i];
       if(i==0)
       y[i]=0;
       else
       {
           if(i&1)y[i]=x[i]-x[i-1]+y[i-1];
           else y[i]=y[i-1]+x[i-1]-x[i];
       }
   }
   int p=read();
   int py=-1;
   for(int i=0;i<n;i++)
   {
       if(x[i]>=p)
       {
           if(x[i]==p)
           py=y[i];
           else{
            if(i&1)py=p-x[i]+y[i];
            else py=x[i]-p+y[i];
           }
           break;
       }
   }
   ll ans=0;
   for(int i=0;i<n;i++)
   {
       if(x[i]>p)break;
       ans=max(ans,(ll)ceil(py-1.0*p*(y[i]-py)/(x[i]-p)));
       //cout<<x[i]<<" "<<y[i]<<endl;
   }
   cout<<ans;
 
}
