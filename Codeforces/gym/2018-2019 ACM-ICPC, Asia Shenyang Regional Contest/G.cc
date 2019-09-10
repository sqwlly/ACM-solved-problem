#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e7+7;
const int maxn=1e6+7;
ll read(){char c=getchar();ll x=0;int f=1;
while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+c-48;c=getchar();}x*=f;return x;}
ll pow(ll a,ll n,ll mod){ll ans=1;while(n){if(n&1)ans=ans*a%mod;a=a*a%mod;n>>=1;}return ans;}
/*int num[200005],cnt;
struct asddddd{int v,next,w;}e[200005];
void add(int u,int v){e[cnt].v=v;e[cnt].next=num[u];num[u]=cnt++;}*/
struct asd{
int x,y,w;
}p[1000050];
map<string,int>mp;
string get(int x)
{
    string a(6,'0');
    int t=0;
    while(x)
    {
        a[t++]=x%10+48;
        x/=10;
    }
    return a;
}
int main()
{
    int T=read();
    int tt=0;
    while(T--)
    {
        int n=read(),m=read();
        mp.clear();
        int cnt=1;
        ll last=0;
        for(int i=0;i<n;i++)
        {
            int x=read(),y=read(),w=read();
            p[cnt]={x,y,w};
            mp[get(x)+get(y)]=cnt++;
            //cout<<get(x)+get(y)<<endl;
        }
        cout<<"Case #"<<++tt<<":\n";
        for(int i=0;i<m;i++)
        {
            int type=read();
            int x=read(),y=read();
            x=(x+last)%6000+1,y=(y+last)%6000+1;
            if(type==1)
            {
                int w=read();
                string s=get(x)+get(y);
                p[cnt]={x,y,w},mp[s]=cnt++;
                //cout<<p[mp[s]].w<<endl;
            }
            else if(type==2)
            {
                mp[get(x)+get(y)]=0;
            }
            else if(type==3)
            {
                int k=read(),w=read();
                int l=ceil(x-sqrt(k))+0.000001,r=sqrt(k)+x;
                l=max(1,l),r=min(r,6000);
                for(int i=l;i<=r;i++)
                {
                    double hh=sqrt(k-(i-x)*(i-x))+y;
                    if(hh==(int)(hh+0.000001))
                    {
                        int h=hh+0.000001;
                        int index=mp[get(i)+get(h)];
                        if(index)
                        p[index].w+=w;
                    }
                    if(sqrt(k-(i-x)*(i-x))==0)continue;
                    hh=-sqrt(k-(i-x)*(i-x))+y;
                    if(hh==(int)(hh+0.000001)&&hh>0)
                    {
                        int h=hh+0.000001;
                        int index=mp[get(i)+get(h)];
                        if(index)
                        p[index].w+=w;
                    }
 
                }
 
            }
            else if(type==4)
            {
                ll ans=0;
                int k=read();
                int l=ceil(x-sqrt(k))+0.000001,r=sqrt(k)+x;
                l=max(1,l),r=min(r,6000);
                //cout<<l<<" "<<r<<endl;
                for(int i=l;i<=r;i++)
                {
                    double hh=sqrt(k-(i-x)*(i-x))+y;
 
                    if(hh==(int)(hh+0.000001))
                    {//cout<<i<<" "<<hh<<endl;
                        int h=hh+0.000001;
                        int index=mp[get(i)+get(h)];
                        //cout<<index<<endl;
                        if(index)
                        ans+=p[index].w;
                    }
                    if(sqrt(k-(i-x)*(i-x))==0)continue;
                    hh=-sqrt(k-(i-x)*(i-x))+y;
 
                    if(hh==(int)(hh+0.000001)&&hh>0)
                    {//cout<<i<<" "<<hh<<endl;
                        int h=hh+0.000001;
                        int index=mp[get(i)+get(h)];
                        //cout<<index<<endl;
                        if(index)
                        ans+=p[index].w;
                    }
 
                }
                cout<<ans<<endl;
                last=ans;
            }//cout<<type<<endl;
        }
 
    }
}
