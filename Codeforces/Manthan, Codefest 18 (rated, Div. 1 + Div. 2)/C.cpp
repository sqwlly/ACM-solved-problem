/*  @ C.cpp
 *  记住, 数组一定要往大开！！！！！！
 *  千万开的恰好！开个1e6, wa了我8次!
 * */

#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
char s[N],b[N];
int main() {
    int n, ans = 0;
    scanf("%d%s%s", &n, s, b);
    for (int i = 0; i < n; ++i) {
        if (s[i] != b[i]) {
            ans++;
            if (s[i] == b[i + 1] && s[i + 1] == b[i]) {
                char t = s[i];
                s[i] = s[i + 1];
                s[i + 1] = t;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}
