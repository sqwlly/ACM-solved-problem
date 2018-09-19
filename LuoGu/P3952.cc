#include<bits/stdc++.h>

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in", "r", stdin);
#endif
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        char t[105] = {0};
        scanf("%d %s", &n, t);
        int o = 0, cnt = 0, ans = 0;
        if (t[2] == '1')
            o = 0;
        else {
            o = t[4] - '0';
            if (isdigit(t[5])) {
                o = o * 10 + t[5] - '0';
            }
        }
        std::stack<char> st;
        std::vector<char> has;
        bool ok = 1, f = 0;
        for (int i = 0; i < n; ++i) {
            char s[105] = {0};
            scanf(" %[^\n]", s);
            int a = 0, b = 0, j;
            for (int j = 4; j < 6 && s[j] != ' '; ++j) {
                if (s[j] == 'n') {
                    a = 1e6;
                    break;
                }
                a = a * 10 + s[j] - '0';
            }
            for (j = 6; j < 9; ++j) {
                if (s[j] == '\n' && j > 6)
                    break;
                if (isdigit(s[j]))
                    b = b * 10 + s[j] - '0';
                if (s[j] == 'n') {
                    b = 1e6;
                    break;
                }
            }
//            printf("%d %d\n",a,b);
            if (s[0] == 'F') {
                if (a < b - 1000) // a = dig, b = n
                    st.push('F');
                else if (a > b && f == 0) // a > b, 注意这里的f!!
                    st.push('G');
                else
                    st.push('K');
            } else {
                char ch = '0';
                if (st.empty())
                    ok = 0;
                else {
                    ch = st.top();
                    st.pop();
                }
                if (!has.empty())
                    has.pop_back();
                else
                    ok = 0;
                if (ch == 'F' && f == 0)
                    cnt--;
                if (ch == 'G')
                    f = 0;
                if (st.empty()) {
//                    printf("last cnt = %d\n",cnt);
                    if (!has.empty())
                        ok = 0;
                }

                continue;
            }
            if (a > b)
                f = 1;
            for (unsigned int i = 0; i < has.size(); ++i) {
                if (has[i] == s[2]) {
                    ok = 0;
                    break;
                }
            }
            if (ok == 1)
                has.push_back(s[2]);
            if (!f && a < b - 1000) {
                cnt++;
//                printf("cnt = %d\n",cnt);
                ans = std::max(ans, cnt);
            }
        }
//		printf("%d %d\n",o,ans);
        if (!ok || !st.empty()) puts("ERR");
        else if (o == ans) {
            puts("Yes");
        } else {
            puts("No");
        }
    }
    return 0;
}


