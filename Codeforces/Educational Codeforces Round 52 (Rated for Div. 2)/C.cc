#include<bits/stdc++.h>

using namespace std;

int n,k,a[200100];
int low[200100];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    cin>>n>>k;
    for(int i = 1; i <= n; ++i){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+n+1);
    int last = 1;
    for(int i = 1; i <= n; ++i){
        for(int j = last; j <= a[i]; ++j){
            low[j] = n - i + 1;
        }
        last = a[i] + 1;
    }
    int h = *max_element(a+1,a+n+1);
    long long ret = 0;
    int cnt = 0;
    for(int i = h; i >= 1; --i){
		if(low[i] == n) break;
        ret += low[i];
        //cout<<low[i]<<'\n';
        if(ret + low[i - 1]> k) {
            cnt++;
            ret = 0;
		}
    }
    cout<<cnt<<endl;
    return 0;
}


