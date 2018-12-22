/*************************************************************************
    > File Name: D2.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com
    > Created Time: 2018年12月22日 星期六 10时39分04秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;

stack<int> st;

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
#endif
    int n, x, max1 = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        max1 = max(max1, x);
        if (!st.empty()) {
            if (st.top() < x) return puts("NO"), 0;
            if (st.top() == x)
                st.pop();
            else
                st.push(x);
        } else {
            st.push(x);
        }
    }
    if (st.size() > 1 || (st.size() == 1 && st.top() < max1)) puts("NO");
    else puts("YES");
    return 0;
}

