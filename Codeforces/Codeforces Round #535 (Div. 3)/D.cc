/*************************************************************************
    > File Name: C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com
    > Created Time: 2019年01月23日 星期三 23时44分34秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    int n;
    cin >> n;
    string s;
    cin >> s;
    //RBRRGG
    //
    string ans = s, t = s;
    //RBGRGRRGG
    //RBGRBRBR
    string tt = "RGB";
    int cnt = 0;
    for(int i = 0; i < n - 1; ++i) {
        if(s[i] == s[i + 1]) {
            for(int j = 0; j < 3; ++j) {
                if(i + 2 < n && s[i + 2] != tt[j] && s[i + 1] != tt[j]) {
                    s[i + 1] = tt[j];
                    cnt++;
                    break;
                }
            }
        }
        if(i == n - 2) {
            if(s[i] == s[i + 1]) {
                for(int j = 0; j < 3; ++j) {
                    if(s[i] != tt[j]) {
                        s[i + 1] = tt[j];
                        cnt++;
                        break;
                    }
                }
            }
        }
    }
    cout<<cnt<<endl;
    cout<<s<<endl;
    return 0;
}

