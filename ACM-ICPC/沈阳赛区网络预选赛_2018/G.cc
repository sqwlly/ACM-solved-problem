#include <iostream>
#include <cstdio>
#include <set>
#include <iterator>
using namespace std;
#define ll long long
const ll MOD=1000000007;
ll shai[1000];
ll prime[100000];
set<int> S;
ll ans;
ll n,m;
ll S_size;

ll POW(ll a,int n)
{
        ll ans = 1;
        ll res = a;
        while(n)
        {
                if(n&1)
                        ans = ((ans%MOD)*(res%MOD))%MOD;
                res = ((res%MOD)*(res%MOD))%MOD;
                n >>= 1;
        }
        return ans%MOD;
}

ll inv(ll n)
{
        return POW(n,MOD-2);
}


ll Spow_n(ll n)
{
        return ((n*(n+1))%MOD*((2*n+1)%MOD))%MOD*inv(6*1LL)%MOD;
}
ll S_n(ll n)
{
        return ((1+n)*n)%MOD*inv(1LL*2)%MOD;
}
void dfs(ll d,ll cnt,ll k)
{
        if(cnt==k)
        {
                ll temp=1;
                for(ll i=0; i<k; i++)
                        temp*=shai[i];
                ll tempb=n/temp;
                ll dirt=(((temp*temp)%MOD*Spow_n(tempb))%MOD+(temp*S_n(tempb))%MOD)%MOD;
                if(k%2==0)
                {
                        ans=(ans%MOD+dirt%MOD)%MOD;
                }
                else
                {
                        if(dirt>ans)
                                ans=ans+MOD-dirt;
                        else
                                ans=(ans-dirt)%MOD;
                }
        }
        for(ll i=d; i<S_size; i++)
        {
                shai[cnt]=prime[i];
                dfs(i+1,cnt+1,k);
        }
}
int main()
{
        while(~scanf("%lld%lld",&n,&m))
        {
                ans=0;
                ll num=m;
                S.clear();
                ll j=2;
                while(j*j<=num)
                {
                        while(num%j==0)
                        {
                                S.insert(j);
                                num/=j;
                        }
                        ++j;
                }
                if(num>1)
                        S.insert(num);
                ans=(ans%MOD+Spow_n(n)%MOD)%MOD;
                ans=(ans%MOD+S_n(n)%MOD)%MOD;
                S_size=S.size();
                set<int>::iterator it=S.begin();
                for(ll i=0; i<S_size; i++)
                {
                        prime[i]=*it;
                        it++;
                }
                for(ll i=1; i<=S_size; i++)
                {
                        dfs(0,0,i);
                }
                cout<<ans%MOD<<endl;
        }
        return 0;
}
