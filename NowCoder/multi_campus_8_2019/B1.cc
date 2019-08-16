#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
long long a[100005],c[100005];
long long b[100005];
int main()
{
    int n;
    cin>>n;
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        a[i]=a[i-1]+i-b[x];
        b[x]++;
        ans+=a[i];
    }
    cout<<ans<<endl;
}
