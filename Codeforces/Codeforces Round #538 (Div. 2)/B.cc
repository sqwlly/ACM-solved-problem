/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com
    > Created Time: 2019年02月10日 星期日 22时20分12秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 2E5+10;
struct node{
    int v,id;
}a[N];

vector<int> v;

bool cmp1(node u,node r)
{
    return u.v < r.v;
}
vector<int> ans1;
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
#endif
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &a[i].v);
        a[i].id = i;
    }

    sort(a + 1, a + n + 1, cmp1);
    long long ans = 0;
    for (int i = 0; i < k * m; ++i) {
        ans += a[n - i].v;
        v.push_back(a[n - i].id);
    }
    sort(v.begin(), v.end());
    cout << ans << endl;
    for (int i = m - 1; i < v.size() - m; i += m) {
        printf("%d%c", v[i], ' ');
    }
    return 0;
}
