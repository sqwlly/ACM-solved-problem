/*************************************************************************
    > File Name: C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com
    > Created Time: 2019年03月23日 星期六 00时16分21秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
typedef long long LL;
using namespace std;
const int N = 3E5+10;
vector<pair<int,int>> v;

priority_queue<LL, vector<LL>, greater<LL> > pq;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, t, b;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) {
        cin >> t >> b;
        v.emplace_back(make_pair(b, t));
    }
    sort(v.begin(), v.end(), greater<pair<int, int>>());
    LL ans = 0, sum = 0;

    for (int i = 0; i < n; ++i) {
        pq.push(v[i].second);
        sum += v[i].second;
        if(pq.size() > k) {
            LL cur = pq.top(); pq.pop();
            sum -= cur;
        }
        ans = max(ans, sum * v[i].first);

    }
    cout << ans << endl;
    return 0;
}

