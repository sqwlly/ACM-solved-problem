/*************************************************************************
    > File Name: C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com
    > Created Time: 2019年03月08日 星期五 00时28分59秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 2E5+10;
int a[N];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a, a + n);
    int maxL = 1, s = 0;
    for(int i = 0; i < n; ++i) {
        while(a[i] - 5 > a[s]) {
            s++;
        }
        maxL = max(maxL, i - s + 1);
    }
    cout << maxL << endl;
    return 0;
}
