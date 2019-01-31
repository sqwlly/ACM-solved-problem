/*************************************************************************
    > File Name: G.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com
    > Created Time: 2019年01月31日 星期四 14时54分28秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
string s[100100];
map<string,int> cnt;
map<string,string> str;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    int n;
    cin >> n;
    char s1[11] = {0};
    for(int i = 0; i < n; ++i) {
        scanf("%s",s1);
        s[i] = s1;
        int len = s[i].length();
        string ret = "";
        for(int j = len - 1; j >= 0; --j) {
            ret += s[i][j];
            cnt[ret]++;
            str[ret] = s[i];
        }
    }
    for(int i = 0; i < n; ++i) {
        reverse(s[i].begin(),s[i].end());
        cout << cnt[s[i]] << endl;
    }
    return 0;
}
