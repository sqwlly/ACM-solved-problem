#include <bits/stdc++.h>
const int N = 1E6+1000;
char s[N],ans[N];
 
int main()
{
    int T,n,i,t;
    for(scanf("%d",&T); T; --T){
        memset(ans,0,sizeof ans);
        for(scanf("%d",&n); n; --n){
            scanf("%s",s);
            int len1 = strlen(ans);
            int len2 = strlen(s);
            for(i = 0, t = 0; i < len1 && t < len2; ++i){
                if(ans[i]==s[t])
                    t++;
            }
            strcpy(ans+len1,s+t);
        }
        puts(ans);
    }
    return 0;
}
