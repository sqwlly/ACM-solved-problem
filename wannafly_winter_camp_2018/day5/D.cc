/*************************************************************************
    > File Name: D.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com
    > Created Time: 2019年02月05日 星期二 14时32分09秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
struct node{
    int a,b;
};
int c[10], r[10], d[10][10], n;
vector<int> g[20][20];
vector<node> X[10];
bool C[10][10], R[10][10];

bool check()
{
    for(int i = 0; i < n; ++i) {
        int sum = 0, j = 0;
        while(d[j][i]) j++;

        for(j = j + 1; d[j][i]; ++j) {
            sum += d[j][i];
        }
        if(sum != c[i]) return 0;
    }
    return 1;
}

void show()
{
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!d[i][j]) putchar('X');
            else cout << d[i][j];
        }
        cout << endl;
    }
    cout<<endl;
}

void dfs(int row,int col) {
    if (col == n) {
        dfs(row + 1, 0);
        return;
    }
    if (row == n) {
        if (check()) {
            show();
            return;
        }
        return;
    }
    int a = X[row][0].a, b = X[row][0].b;
    if (col > a && col < b) {
        for (auto &S : g[r[row]][b - a - 1]) {
            for (int i = 0; i < n - 2; ++i) {
                if ((S & (1 << i)) && C[col][i] == 0 && R[row][i] == 0) {
                    C[col][i] = R[row][i] = 1;
                    d[row][col] = i + 1;
                    dfs(row, col + 1);
                    d[row][col] = 0;
                    C[col][i] = R[row][i] = 0;
                }
            }
        }
    } else {
        if (col == a || col == b) {
            dfs(row, col + 1);
        }
        for (auto &S : g[r[row]][b - a - 1]) {
            for (int i = 0; i < n - 2; ++i) {
                if ((S & (1 << i)) == 0 && C[col][i] == 0 && R[row][i] == 0) {
                    C[col][i] = R[row][i] = 1;
                    d[row][col] = i + 1;
                    dfs(row, col + 1);
                    d[row][col] = 0;
                    C[col][i] = R[row][i] = 0;
                }
            }
        }
    }
}

void dfs_(int row)
{
    if(row == n) {
        memset(R,0,sizeof R);
        memset(C,0,sizeof C);
        dfs(0,0);
        return;
    }
    for(int i = 0; i < n; ++i) {
        for(int j = i + 1; j < n; ++j) {
            if(g[r[row]][j - i - 1].size()) {
                X[row].push_back(node{i,j});
                dfs_(row + 1);
                X[row].pop_back();
            }
        }
    }
}

void init()
{
    int t = 0;
    for(int i = 0; i < n - 2; ++i) {
        t |= 1 << i;
    }
    g[0][0].push_back(0);
    g[15][5].push_back(t);
    for(int s = (t - 1) & t; s != 0; s = (s - 1) & t) {
        int sum = 0, cnt = 0;
        for(int i = 0; i < n - 2; ++i) {
            if(1 & (s >> i)) {
                sum += i + 1;
                cnt++;
            }
        }
        g[sum][cnt].push_back(s);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        for (auto &i : g)
            i->clear();
        init();
        memset(d, 0, sizeof d);
        for(int i = 0; i < 2; ++i) {
            for(int j = 0; j < n; ++j) {
                if(i) cin >> c[j];
                else cin >> r[j];
            }
        }
        dfs_(0);
    }
    return 0;
}

