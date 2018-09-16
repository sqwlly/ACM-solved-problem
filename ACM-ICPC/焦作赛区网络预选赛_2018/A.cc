#include <bits/stdc++.h>
typedef long long LL;
const int N = 1e5;
char s[N];
int main(int argc, char const *argv[]) {
        int T;
        scanf("%d", &T);
        while (T--) {
                scanf("%s", s);
                for(int i = 0; s[i]; ++i) {
                        if(isupper(s[i])) {
                                s[i] = s[i] - 'A' + 'a';
                        }
                }
                if(strcmp(s,"jessie")==0) {
                        printf("Good guy!\n");
                }else{
                        printf("Dare you say that again?\n");
                }
        }
        return 0;
}
