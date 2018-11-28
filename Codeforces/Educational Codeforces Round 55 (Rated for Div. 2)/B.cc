/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com
    > Created Time: 2018年11月28日 星期三 23时01分05秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
struct node{
    int st,len;
}a[100100];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    int n;
    string s;
    cin >> n >> s;
    vector<int> idx;
    int maxl = 0, cnt = 0, k = 0, f = 0;
    if(s[0] == 'G') cnt++, a[0].st = 0;
    for(int i = 1; i < s.length(); ++i) {
        if(s[i] == 'G' && s[i - 1] == 'G') {
            cnt++;
            maxl = max(maxl, cnt);
        }else{
            if(s[i] != 'G')
            a[k++].len = cnt;
            cnt = 0;
            if(s[i] == 'G') cnt++,a[k].st = i;
        }
        if(i == s.length() - 1) {
            if(s[i] == 'G') a[k].len = cnt;
        }
        if(s[i] == 'S' && s[i - 1] == 'G' && s[i + 1] == 'G') {
            f = 1;
            idx.push_back(i);
        }
    }
    for(int i = 0; i < idx.size(); ++i) {
        for(int j = 0; j < k; ++j) {
            if(idx[i] >= a[j].st) {
                int t = a[j].len + a[j + 1].len + 1;
                if(k <= 2) t--;
                maxl = max(maxl, t);
            }
        }
    }
    //cout<< k << endl;
    for(int i = 1; i < k; ++i) {
        if(a[i].st - 1 == a[i - 1].st + a[i - 1].len) {
            maxl = max(maxl,a[i].len + a[i - 1].len + 1);
        }
    }
    cout << maxl << endl;
    return 0;
}

