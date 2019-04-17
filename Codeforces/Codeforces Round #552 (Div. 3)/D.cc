/*************************************************************************
    > File Name: C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com
    > Created Time: 2019年04月16日 星期二 23时24分17秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 2E5+10;
int x[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
    int n,a,b;
    cin >> n >> b >> a;
    for(int i = 1; i <= n; ++i) {
        cin >> x[i];
    }
    int ta = a, tb = b;
    for(int i = 1; i <= n; ++i) {
        if(x[i]) {
            if(tb > 0 && ta + 1 <= a) {
                tb--;
                if(ta + 1 <= a) ta++;
            }else if(ta > 0){
                ta--;
            }else{
                return cout << i - 1 << endl,0;
            }
        }else{
            if(ta > 0) {
                ta--;
            }else if(tb > 0) {
                tb--;
            }else{
                return cout << i - 1<< endl,0;
            }
        }
    }
    cout << n << endl;
    return 0;
}

