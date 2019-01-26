/*************************************************************************
    > File Name: E1.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com
    > Created Time: 2019年01月25日 星期五 19时41分34秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
int a[301],l[301],r[301];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    int n,m;
    cin >> n >> m;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for(int i = 0; i < m; ++i) {
        cin >> l[i] >> r[i];
        l[i]--, r[i]--;
    }
    int ans = 0;
    vector<int> v;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(i == j) continue;
            int dif = a[j] - a[i], cnt = 0;
            int tmp[301] = {0};
            for(int k = 0; k < m; ++k) {
                if(l[k] <= i && r[k] >= i && (l[k] > j || r[k] < j)) {
                    dif++;
                    tmp[cnt++] = k + 1;
                }
            }
            if(dif > ans) {
                ans = dif;
                v.clear();
                for(int k = 0; k < cnt; ++k) {
                    v.push_back(tmp[k]);
                }
            }
        }
    }
    cout << ans << endl << v.size() << endl;
    for(int i = 0; i < v.size(); ++i) {
        printf("%d%c",v[i], i == v.size() - 1 ?'\n' :' ');
    }
    return 0;
}

