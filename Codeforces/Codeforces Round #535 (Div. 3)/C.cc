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
    int min1 = 1e9;
    string ans = s, t = s;
    string v[6] = {"RGB","RBG","BRG","BGR","GRB","GBR"};
    int k = 0;
    while(k < 6)
    {
        int cnt = 0;
        s = ans;
        for(int i = 0; i < n; ++i) {
            if(s[i] != v[k][i % 3]) {
                cnt++;
                s[i] = v[k][i % 3];
            }
        }
        if(min1 > cnt) {
            min1 = cnt;
            t = s;
        }
        //cout<<v[k]<<endl;
        k++;
    }
    cout<<min1<<endl;
    cout<<t<<endl;
    return 0;
}

