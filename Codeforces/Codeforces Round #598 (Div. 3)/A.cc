#include<bits/stdc++.h>

using namespace std;

int main()
{
  //  freopen("input.in","r",stdin);
    long long q,a,b,n,S;
    cin >> q;
    while(q--) {
        cin >> a >> b >> n >> S;
        bool ok = 0;
        if(a * n <= S) {
            if(a * n + b >= S) ok = 1;
        }else{
            if(S / n * n + b >= S) {
                ok = 1;
            }
        }
        cout << (ok ? "Yes" : "No") << '\n';
    }
    return 0;
}