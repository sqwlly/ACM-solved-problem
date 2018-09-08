#include <bits/stdc++.h>
typedef long long LL;
const int N = 1e3+10;
char s[N];
int ans[50] = {1,2,3,5,7,11,13,17,23,31,37,53,71,73,113,131,137,173,311,317};
int main()
{
        int T,w = 0;
        scanf("%d", &T);
        while(T--) {
                scanf("%s", s);
                int num = 0, k = 0, ret = 0;
                do {
                        int t = s[k++]-'0';
                        num = num*10 + t;
                        if(k >= 4||num>=317) {
                                ret = 317;
                                break;
                        }
                } while(s[k]);
                int i;
                for(i = 0; ans[i] <= 317 && ans[i]; ++i) {
                        if(num < ans[i]) {
                                ret = ans[i-1];
                                break;
                        }
                }
                if(ans[i] == 0) {
                        ret = 317;
                }
                printf("Case #%d: %d\n",++w,ret);
        }

}
