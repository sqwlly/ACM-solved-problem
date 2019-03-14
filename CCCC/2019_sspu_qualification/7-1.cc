/*************************************************************************
    > File Name: 7-2.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com
    > Created Time: 2019年03月13日 星期三 20时51分44秒
 ************************************************************************/

#include <stdio.h>
#include <string.h>
#include <math.h>
#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

char ans[1002][1002] = {0},s[10100] = {0};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
  //  ios::sync_with_stdio(false); cin.tie(0);
    int n;
    scanf("%d ",&n);
    for(int i = 0; i < 1002; ++i) {
        for(int j = 0; j < 1002; ++j) ans[i][j] = ' ';
    }
    //string s;
    //getline(cin,s);
    gets(s);
    int k = 0, len = strlen(s), m = ceil(len * 1.0 / n);
    for(int i = m; i >= 1; --i) {
        for(int j = 1; j <= n; ++j) {
            ans[j - 1][i - 1] = s[k++];
            if(k == len) break;
        }
        if(k == len) break;
    }
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            putchar(ans[i][j]);
        }
        puts("");
    }
    return 0;
}

