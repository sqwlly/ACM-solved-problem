/*************************************************************************
    > File Name: L3_003.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com
    > Created Time: 2019年03月03日 星期日 11时39分47秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 1010;
int f[2 * N + 10], p[N];

int getf(int v)
{
    if(f[v] == v) return v;
    return f[v] = getf(f[v]);
}

int getp(int v)
{
    if(p[v] == v) return v;
    return p[v] = getp(p[v]);
}

void merge(int u,int v)
{
    int fx = getf(u);
    int fy = getf(v);
    if(fx != fy) {
        f[fx] = fy;
    }
}

void join(int u,int v)
{
    int p1 = getp(u);
    int q1 = getp(v);
    if(p1 != q1) {
        p[p1] = q1;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
    int n,k,y;
    string s;
    cin >> n;
    for(int i = 0; i < 2 * N; ++i) f[i] = i;
    for(int i = 0; i < N; ++i) p[i] = i;
    for(int i = 1; i <= n; ++i) {
        cin >> s;
        k = s[0] - '0';
        for(int j = 0; j < k; ++j) {
            cin >> y;
            int fa = getf(y);
            if(fa != y) {
                join(i,fa - N);
            }
            merge(y,i + N);
        }
    }
    int sum[1010] = {0};
    for(int i = 1; i <= n; ++i) {
        sum[getp(i)]++;
    }
    sort(sum, sum + 1010, greater<int>());
    int cnt = 0;
    for (int i : sum) if(i) cnt++;
    cout << cnt << endl;
    for(int i = 0; i < 1010; ++i) {
        if(sum[i] == 0) {
            break;
        }
        cout << sum[i] << (sum[i + 1] == 0 ? '\n' :' ');
    }
    return 0;
}

