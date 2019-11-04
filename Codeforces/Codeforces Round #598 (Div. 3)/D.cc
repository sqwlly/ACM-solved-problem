#include<bits/stdc++.h>

using namespace std;
typedef long long LL;
constexpr int N = 1E6+10;
bool one[N];
int main()
{
    freopen("input.in","r",stdin);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int q;
    LL n,k;
    string s;
    cin >> q;
    while(q--) {
        cin >> n >> k >> s;
        int top = -1;
        for(int i = 0; i < s.size(); ++i) {
            one[i] = 1;
            if(s[i] == '1' && top == -1) top = i; 
        }
        for(int i = 0; i < s.size(); ++i) {
            if(s[i] == '0' && k > 0) {
                int cst = max(0, i - top);
                cst = min(k, cst * 1LL);
             //   cout << i + 1 << ' ' << cst << '\n';
                one[i - cst] = 0;
                top = i - cst + 1;
                k -= cst;
                if(i - 1 >= 0)
                s[i] = s[i - 1];
            }
        }
        for(int i = 0; i < s.size(); ++i) {
            if(one[i] == 0) {
                cout << 0;
            }else{
                cout << s[i];
            }
        }
        cout << '\n';
    }
    return 0;
}