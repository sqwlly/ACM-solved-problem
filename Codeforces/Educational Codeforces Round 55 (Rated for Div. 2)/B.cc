#include <bits/stdc++.h>

using namespace std;

int main() {
    string str;
    int n;
    cin >> n;
    cin >> str;
    int res = 0;
    int cntG = 0, sumG = 0, ccG = 0;
    for (int i = 0; i < n; ++i) {
        if (str[i] == 'G') {
            sumG++;
            cntG++;
        } else {
            ccG = cntG;
            cntG = 0;
        }
        res = max(res, ccG + cntG + 1);
    }
    res = min(sumG, res);
    cout << res << endl;
    return 0;
}
