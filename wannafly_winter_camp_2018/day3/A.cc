/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com
    > Created Time: 2019年02月04日 星期一 10时19分23秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
vector<double> S;

struct node{
    vector<double> v;
};

int bfs()
{
    queue<node> q;
    node cur;
    for(int i = 0; i < S.size(); ++i) {
        cur.v.push_back(S[i]);
    }
    q.push(cur);
    while(!q.empty()) {
        cur = q.front(); q.pop();
        vector<double> v = cur.v;
        for(int i = 0; i < v.size(); ++i)
            if(fabs(v[i] - 24.0) < 1e-8) return 1;
        bool vis[20] = {0};
        for(int i = 0; i < v.size(); ++i) {
            for(int j = i + 1; j < v.size(); ++j) {
                double a = v[i], b = v[j];
                vis[i] = vis[j] = 1;
                for(int k = 0; k < 6; ++k) {
                    if(k == 0) {
                        v.push_back(a + b);
                    }else if(k == 1) {
                        v.push_back(a - b);
                    }else if(k == 2) {
                        v.push_back(b - a);
                    }else if(k == 3) {
                        v.push_back(a * b);
                    }else if(k == 4){
                        v.push_back(a / b);
                    }else{
                        v.push_back(b / a);
                    }
                    node nxt;
                    for(int i = 0; i < v.size(); ++i) {
                        if(vis[i] == 0) {
                            nxt.v.push_back(v[i]);
                        }
                    }
                    v.pop_back();
                    q.push(nxt);
                }
                vis[i] = vis[j] = 0;
            }
        }
    }
    return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    int n, ans = 0;
    cin >> n;
    for(int i = 0; i < (1 << n); ++i) {
        S.clear();
        for(int j = 0; j < n; ++j) {
            if(i & (1 << j)) {
                S.push_back(j + 1);
            }
        }
        ans += bfs();
    }
    cout << ans << endl;
    return 0;
}

