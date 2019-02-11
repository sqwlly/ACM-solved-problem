/*************************************************************************
    > File Name: C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com
    > Created Time: 2019年02月11日 星期一 10时44分40秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
typedef long long LL;
using namespace std;
vector<pair<LL,int> > v;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    LL n,b;
    cin >> n >> b;
    for(LL i = 2; i * i <= b; ++i) {
        if(b % i == 0)
            v.emplace_back(make_pair(i,0));
        while(b % i == 0) {
            b /= i;
            v.back().second++;
        }
    }
    if(b > 1) {
        v.emplace_back(make_pair(b,1));
    }
    LL k = 1E18;
    for(int i = 0; i < v.size(); ++i) {
        LL t = n, ret = 0;
        while(t > 0) {
            ret += t / v[i].first;
            t /= v[i].first;
        }
        k = min(k, ret / v[i].second);
    }
    cout << k << endl;
    return 0;
}

