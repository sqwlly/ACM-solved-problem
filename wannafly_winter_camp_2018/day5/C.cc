/*************************************************************************
    > File Name: C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com
    > Created Time: 2019年01月24日 星期四 13时36分21秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
int a[101000];
priority_queue<int> pq;

int C(int &a,int b)
{
    int cnt = 0;
    while(a >= b) {
        a >>= 1;
        cnt++;
    }
    return cnt;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; ++i) {
        scanf("%d",&a[i]);
        pq.push(a[i]);
    }
    long long ans = 0;
    for(int i = 0; i < k; ) {
        int cur = pq.top(); pq.pop();
        int nxt = pq.top();
        int cnt = C(cur,nxt);
        i += cnt;
        pq.push(cur);
    }
    while(!pq.empty())
    {
        ans += pq.top();
        pq.pop();
    }
    cout << ans << endl;
    return 0;
}

