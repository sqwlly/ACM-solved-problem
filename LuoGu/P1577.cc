/*************************************************************************
    > File Name: P1577.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年09月26日 星期三 22时47分14秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;

int n,k;

double a[10010];

bool ok(int len)
{
    int ret = 0;
    for(int i = 0; i < n; ++i){
        ret += a[i]/len;
    }
    return ret >= k;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    cin>>n>>k;
    for(int i = 0; i < n; ++i){
        cin>>a[i];
        a[i] *= 100;
    }
    int l = 0, r = 100000000;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(mid == 0)
            break;
        if(ok(mid))
            l = mid+1;
        else
            r = mid-1;
    }
    printf("%.2f\n",1.0*r/100);
    return 0;
}

