#include<bits/stdc++.h>
typedef long long LL;
const int N = 1E5+10, inf = 1e9;

LL Ceil(LL n,LL k)
{
    if(k%n==0){
        return k/n;
    }else{
        return k/n+1;
    }
}

int main() {
    LL n,k;
    scanf("%lld%lld",&n,&k);
    LL ans = Ceil(n,k);
    printf("%lld\n",ans);
    return 0;
}
