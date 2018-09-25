/*************************************************************************
    > File Name: P1230.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com
    > Created Time: 2018年09月25日 星期二 16时40分49秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;

struct pig{
    int v,t;
    bool operator < (const pig & u)const{
        if(v == u.v)
            return t < u.t;
        return v > u.v;
    }
}a[520];

bool vis[520];

int main()
{
//#ifndef ONLINE_JUDGE
//    freopen("riddle.in","r",stdin);
//	freopen("riddle.out","w",stdout);
//#endif
    int n,m,sum = 0;
    cin>>m>>n;
    for(int i = 0; i < n; ++i)
        cin>>a[i].t;
    for(int i = 0; i < n; ++i)
        cin>>a[i].v;
    sort(a,a+n);
    for(int i = 0; i < n; ++i){
        for(int j = a[i].t-1; j >= 0; --j){
            if(vis[j] == 0)
            {
                vis[j] = 1;
                a[i].t = -1;
                break;
            }
        }
    }
    for(int i = 0; i < n; ++i)
        if(~a[i].t){
//            printf("%d\n",i);
            m -= a[i].v;
        }
    cout<<m<<endl;
    return 0;
}

