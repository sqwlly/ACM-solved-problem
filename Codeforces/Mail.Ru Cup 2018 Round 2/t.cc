#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const int MAXN = 1e5+1e3;
bool vis[MAXN];
ll a[MAXN];
int main() {
    int n, m, l;
    scanf("%d%d%d", &n, &m, &l);
    int ans = 0;
    for(int i=1; i<=n; i++) {
        scanf("%I64d", a+i);
        if(a[i]>l) {
            vis[i] = true;
            if(!vis[i-1]) ++ans;
        }
    }
    while(m--) {
        int t; scanf("%d", &t);
        if(!t) printf("%d\n", ans);
        else {
            int p, d;
            scanf("%d%d", &p, &d);
            a[p] += d;
            if(!vis[p]&&a[p]>l) {
                vis[p] = true;
                if(vis[p-1]&&vis[p+1]) {
                    ans -= 1;
                }else if(!vis[p-1]&&!vis[p+1]){
                    ans += 1;
                }
            }
        }
    }
    
    return 0;
}
