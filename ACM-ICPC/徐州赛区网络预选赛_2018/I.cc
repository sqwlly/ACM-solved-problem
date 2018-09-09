#include <bits/stdc++.h>
typedef long long LL;
const int N = 1e6+10;

char s[N];

int main(int argc, char const *argv[]) {
        int T,n;
        scanf("%d", &T);
        while(T--) {
                char d;
                int ans = 0;
                scanf("%d %c", &n,&d);
                scanf("%s", s);
                for(int i = 0; s[i]; ++i) {
                        if(fabs(d-s[i])) {
                                ans = (n-i)*2;
                                if(fabs(d-s[i])<10)
                                        ans--;
                                break;
                        }
                }
                if(ans==0) ans++;
                printf("%d\n", ans);
        }
        getchar();
        return 0;
}
