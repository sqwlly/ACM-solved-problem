/*************************************************************************
    > File Name: C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com
    > Created Time: 2019年04月20日 星期六 20时48分36秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl
typedef long long LL;
using namespace std;
const int N = 1E5+10;
int n;
string s;
int cnt[20];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T = 1;
    while (cin >> n && n != 0) {
        assert(n <= 10);
        if (T != 1) cout << endl;
        cin >> s;
        for (int i = 0; i < n; ++i) {
            cnt[i] = 3;
        }
        cnt[11] = 0;
        int step = 0, cur = 0, c = n;
        while (1) {
            int k = min(3, cnt[cur]);
            if (c == 1 || s.length() - step < k) break;
            for (int i = 0; i < k; ++i, step++) {
                if (s[step] == 'L') {
                    cnt[(cur + 1) % n]++;
                    cnt[cur]--;
                    if (cnt[(cur + 1) % n] == 1) c++;
                    if (cnt[cur] == 0) c--;
                } else if (s[step] == 'R') {
                    cnt[(cur - 1 + n) % n]++;
                    cnt[cur]--;
                    if (cnt[(cur - 1 + n) % n] == 1) c++;
                    if (cnt[cur] == 0) c--;
                } else if (s[step] == 'C') {
                    cnt[11]++;
                    cnt[cur]--;
                    if (cnt[cur] == 0) c--;
                }
            }
            cur = (cur + 1) % n;
        }
        if (c == 1) {
            for (int i = 0; i < n; ++i) {
                if (cnt[i]) {
                    cur = i;
                    break;
                }
            }
        }
        cout << "Game " << T++ << ":\n";
        for (int i = 0; i < n; ++i) {
            cout << "Player " << (i + 1) << ":" << cnt[i];
            if (cur == i) {
                if (c == 1)cout << "(W)";
                else cout << "(*)";
            }
            cout << endl;
        }
        cout << "Center:" << cnt[11] << endl;
    }

    return 0;
}
