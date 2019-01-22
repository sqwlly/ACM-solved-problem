/*************************************************************************
    > File Name: G.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com
    > Created Time: 2019年01月22日 星期二 13时54分35秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
const int N = 1E5+10;
int p[N],A[N],q[N];

struct node{
    int A1,len;
    bool operator < (const node &u) const{
        return A1 < u.A1;
    }
}f[N];
vector<int> v;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) {
        scanf("%d",&f[i].A1);
        f[i].len = i;
        v.push_back(i);
    }
    sort(f + 1, f + n + 1);
    int t = n;
    for(int i = 1; i <= n; ++i) {
        A[f[i].len] = t--;
 //       printf("%d%c",f[i].len, i == n ?'\n' :' ');
    }
    A[n] = 1;
    for(int i = n - 1; i >= 1; --i) {
        if(f[i].len > f[i + 1].len) {
            A[i] = A[i + 1] + 1;
        }else{
            A[i] = A[i + 1];
        }
    }
    for(int i = 1; i <= n; ++i) {
  //      printf("%d%c",A[i], i == n ?'\n' :' ');
    }
    p[1] = A[1];
    v.erase(lower_bound(v.begin(),v.end(),A[1]));
    for(int i = 2; i <= n; ++i) {
        vector<int>::iterator iter = upper_bound(v.begin(),v.end(),A[i]);
        if(A[i] == A[i - 1]) {
            p[i] = *iter;
            v.erase(iter);
        }else{
            p[i] = A[i];
            iter = lower_bound(v.begin(),v.end(),p[i]);
            v.erase(iter);
        }
    }
    for(int i = 1; i <= n; ++i) {
        printf("%d%c",p[i], i == n ? '\n' :' ');
    }
    return 0;
}

