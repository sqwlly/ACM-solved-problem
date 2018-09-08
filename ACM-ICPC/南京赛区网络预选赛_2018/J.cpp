/*  @J.cpp 欧拉线性筛+思维
 *  题解: https://blog.csdn.net/Eternally831143/article/details/82315353
 * */
#include<bits/stdc++.h>
using namespace std;
const int N = 2e7+10;

int prime[N],f[N];
bool vis[N];

void fuck() {
    f[1] = 1;
    for (int i = 2, k = 0; i < N; ++i) {
        if (vis[i] == 0)
            prime[k++] = i, f[i] = 2;
        for (int j = 0; prime[j] * i < N && j < k; ++j) {
            int num = i * prime[j];
            vis[num] = 1;
            if (i % prime[j])
                f[num] = f[i] * f[prime[j]]; // f[num] = f[i] * 2
            else if (i % (prime[j] * prime[j]) == 0)
                f[num] = 0;
            else {
                f[num] = f[num / (prime[j] * prime[j])];
                break;
            }
        }
    }
}


int main() {
    int T, n;
    fuck();
    for (int i = 1; i < N; ++i)
        f[i] += f[i - 1];
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        printf("%d\n", f[n]);
    }
    return 0;
}
