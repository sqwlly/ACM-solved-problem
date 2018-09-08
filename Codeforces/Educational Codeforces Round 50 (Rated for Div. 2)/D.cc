#include<bits/stdc++.h>
typedef long long LL;
const int N = 3E5+10, inf = 1e9;

int a[N],b[N];

int main() {
    int n,m;
    scanf("%d",&n);
    for(int i = 0; i < n; ++i){
        scanf("%d",&a[i]);
    }
    scanf("%d",&m);
    for(int i = 0; i < m; ++i){
        scanf("%d",&b[i]);
    }
    int len = std::max(n,m);
//    std::vector<LL> v;
    int x = 0, y = 0, cnt = 0;
    LL sum1 = 0, sum2 = 0;
    while(x < n || y < m){
        if(a[x]==b[y]) {
//            v.push_back(a[x]);
            x++,y++;
            cnt++;
        }
        if(a[x]!=b[y]){
            sum1 = a[x++];
            sum2 = b[y++];
        }
        while(sum1 != sum2) {
            if(x > n|| y > m){
                puts("-1");
                return 0;
            }
            if (sum1 > sum2) {
                sum2 += b[y++];
            }
            if (sum2 > sum1) {
                sum1 += a[x++];
            }
        }
        if(sum1 == sum2 && sum1 != 0) {
            cnt++;
            sum1 = sum2 = 0;
        }
    }
    printf("%d\n",cnt);
    return 0;
}
