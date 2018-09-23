/*************************************************************************
    > File Name: P2827.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com
    > Created Time: 2018年09月20日 星期四 22时35分22秒
	> 题解：https://blog.csdn.net/Eternally831143/article/details/82826584
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
const int N = 7000010;
int n,m,q,u,v,t,a[N],b[N],c[N];

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
#endif
    vector<int> ans;
    cin >> n >> m >> q >> u >> v >> t;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int front1 = 0, rear1 = n, front2 = 0, rear2 = 0, front3 = 0, rear3 = 0;
    sort(a, a + n, greater<int>());
    int tmp, sum = 0;
    double p = 1.0 * u / v;
    for (int i = 1; i <= m; ++i) {
        if (front1 < rear1) {
            if (a[front1] >= max(b[front2], c[front3])) {
                tmp = a[front1++];
            } else if (b[front2] >= max(a[front1], c[front3])) {
                tmp = b[front2++];
            } else {
                tmp = c[front3++];
            }
        } else {
            if (b[front2] > c[front3])
                tmp = b[front2++];
            else
                tmp = c[front3++];
        }
        tmp += sum; //加上标记
        sum += q; //更新标记
        int x = floor(p * tmp), y = tmp - x;
        x -= sum, y -= sum;
        b[rear2++] = x, c[rear3++] = y;
        if (i % t == 0)
            cout << tmp << ' ';
    }
    puts("");
    for (int i = front1; i < rear1; ++i)
        ans.push_back(a[i]);
    for (int i = front2; i < rear2; ++i)
        ans.push_back(b[i]);
    for (int i = front3; i < rear3; ++i)
        ans.push_back(c[i]);
    sort(ans.begin(), ans.end(), greater<int>());
    for (int i = 0; i < ans.size(); ++i) {
        if ((i + 1) % t == 0)
            cout << ans[i] + sum << ' ';
    }
    return 0;
}
