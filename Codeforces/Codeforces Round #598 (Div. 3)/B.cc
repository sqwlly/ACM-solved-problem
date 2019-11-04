#include<bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("input.in","r",stdin);
    //5 4 1 3 2
    //5 1 4 3 2
    int q;
    cin >> q;
    while(q--) {
        int n;
        cin >> n;
        int a[102] = {0};
        vector<pair<int,int>> p;
        for(int i = 1; i <= n; ++i) {
            cin >> a[i];
            p.push_back(make_pair(a[i],i));
        }
        bool vis[102] = {0};
     /*   
        for(int i = 1; i <= n; ++i) {
            for(int j = i; j > 1; --j) {
                if(a[j] < a[j - 1] && vis[j - 1] == 0) {
                    vis[j - 1] = 1;
                    swap(a[j], a[j - 1]);
                }
            }
        }*/
        
        vector<int> ans;
        sort(p.begin(), p.end());
        for(int i = 0; i < n; ++i) {
            if(vis[p[i].second] == 0) {
                for(int j = p[i].second; j > 1; --j) {
                    if(vis[j - 1] == 0 && a[j] < a[j - 1]) {
                        vis[j - 1] = 1;
                        swap(a[j - 1], a[j]);
                    }else{
                        break;
                    }
                }
            }
        }
        for(int i = 1; i <= n; ++i) {
            cout << a[i] << " \n"[i == n];
        }
    }
    return 0;
}