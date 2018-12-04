/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年12月03日 星期一 09时32分26秒
 ************************************************************************/
#include<bits/stdc++.h>

using namespace std;
const int N = 100100;
int prime[N];
bool vis[N];

int init()
{
    int k = 0;
    for(int i = 2; i < N; ++i) {
        if(vis[i] == 0)
            prime[k++] = i;
        for(int j = 2; j * i < N; ++j) {
            if(vis[i * j] == 0)
                vis[i * j] = 1;
        }
    }
    return k;
}

bool book[N];
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
#endif
    int T, a, b, k = init(), w = 1;
    cin >> T;
    while (T--) {
        cin >> a >> b;
        memset(book, 0, sizeof book);
        for (int i = 0; i < k && prime[i] <= sqrt(b); ++i) {
            int t = prime[i] * ceil(1.0 * a / prime[i]);
            if (t % prime[i] == 0 && t != prime[i])
                book[t - a] = 1;
            for (int j = 1; j * prime[i] <= b - a; ++j) {
                int tmp = j * prime[i] - a + t;
                if (book[tmp] == 0)
                    book[tmp] = 1;
            }
        }
        int cnt = 0;
        for (int i = a; i <= b; ++i)
            if (book[i - a] == 0) {
                cnt++;
            }
        if (a == 1) cnt--;
        cout << "Case " << w++ << ": " << cnt << endl;
    }
    return 0;
}

