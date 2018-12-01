#include <iostream>
#include <bits/stdc++.h>

using namespace std;
vector < long long> v[100100];
long long a[100100];
int main()
{
    long long n,m,x,y,i;  cin>>n>>m;
    for(i=0;i<n;i++){
        cin>>x>>y;
        v[x].push_back(y);
    }
    for(i=1;i<=m;i++){
        if(v[i].size()>0){
            sort(v[i].rbegin(),v[i].rend());
            for(long long j=1;j<v[i].size();j++){
                v[i][j]=v[i][j]+v[i][j-1];
            }
        }
    }
    for(long long i=1;i<=m;i++){
        for(long long j=0;j<v[i].size();j++){
            if(v[i][j]>0)
            a[j]+=v[i][j];
        }
    }
    long long Answer=0;
    for(long long i=0;i<=n;i++)
        Answer=max(Answer,a[i]);
    cout<<Answer;
    return 0;
}
