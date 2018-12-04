#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
vector <LL> v[100100];
LL a[100100];
int main()
{
    LL n,m,x,y,i;  cin>>n>>m;
    for(i=0;i<n;i++){
        cin>>x>>y;
        v[x].push_back(y);
    }
    for(i=1;i<=m;i++){
        if(v[i].size()>0){
            sort(v[i].rbegin(),v[i].rend());
            for(LL j=1;j<v[i].size();j++){
                v[i][j]=v[i][j]+v[i][j-1];
            }
        }
    }
    for(LL i=1;i<=m;i++){
        for(LL j=0;j<v[i].size();j++){
            if(v[i][j]>0)
            a[j]+=v[i][j];
        }
    }
    LL Answer=0;
    for(LL i=0;i<=n;i++)
        Answer=max(Answer,a[i]);
    cout<<Answer;
    return 0;
}

