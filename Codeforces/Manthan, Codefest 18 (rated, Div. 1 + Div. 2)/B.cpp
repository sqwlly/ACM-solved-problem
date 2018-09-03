#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+10;

int a[N];
int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i) {
        scanf("%d", a + i);
    }
    sort(a, a + n);
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        if (i <= n / 2) {
            if (a[i] >= k) {
                ans += a[i] - k;
                a[i] = k;
            } else if (i == n / 2) {
                ans += k - a[i];
                a[i] = k;
            }
        } else {

            if (a[i] < a[i - 1]) {
                ans += k - a[i];
                a[i] = k;
            }
        }
    }
    printf("%lld\n", ans);
    return 0;
}
