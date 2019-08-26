#include<bits/stdc++.h>
using namespace std;
typedef long long  ll;
ll mi[105],ai[105],f[105];
ll lcm(ll a,ll b){
    return a/__gcd(a,b)*b;
}
ll three[1001000];
int main(){
	int T;
	for(int i = 1; i < 1001000; ++i) three[i] = 1LL * i * i * i;
	cin >> T;
	while(T--) {
    ll n,m;
	n = 3;
    for(int i=1;i<=n;i++)
        scanf("%lld",&mi[i]);
	for(int i =1; i <= n; ++i) 
		scanf("%lld",&ai[i]);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
             ll d=__gcd(mi[i],mi[j]);
            if(ai[i]%d!=ai[j]%d){
                assert(0);
                return 0;
            }  
        }
    }
    f[1] = ai[1];
    ll y=mi[1];
    for(int i=2;i<=n;i++){
        f[i] = f[i-1];
        while(f[i]%mi[i]!=ai[i]){
            f[i]+=y;
        }
        y=lcm(y,mi[i]);
    }
	printf("%lld\n",(long long)ceil(pow(f[n],1.0/3)));

	}
    return 0;
}
