/*************************************************************************
    > File Name: C1.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com
    > Created Time: 2019年04月26日 星期五 23时15分51秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 2e5+10;
int a[N],c[N];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
    int n;
    cin >> n;
    string ans = "";
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int l = 0, r = n - 1, k = 1;
    if(a[l] > a[r]) {
        c[0] = a[r--];
        ans += 'R';
    }else{
        c[0] = a[l++];
        ans += 'L';
    }
    while(l < r) {
        if(a[l] > a[r]) {
            if(a[r] <= c[k - 1]) {
                if(a[l] > c[k - 1]) {
                    c[k++] = a[l++];
                    ans += 'L';
                }else{
                    break;
                }
            }
            if(a[r] > c[k - 1]) {
                c[k++] = a[r--];
                ans += 'R';
            }
        }else if(a[l] < a[r]){
            if(a[l] <= c[k - 1]) {
                if(a[r] > c[k - 1]){
                    c[k++] = a[r--];
                    ans += 'R';
                }else{
                    break;
                }
            }
            if(a[l] > c[k - 1]){
                c[k++] = a[l++];
                ans += 'L';
            }
        }else{
            vector<int> p = {c[k - 1]}, q = {c[k - 1]};
            string p_s = "", q_s = "";
            for(int i = l; i < r; ++i) {
                if(a[i] > p.back()) {
                    p_s += 'L';
                    p.emplace_back(a[i]);
                }else{
                    break;
                }
            }
            for(int i = r; i > l; --i) {
                if(a[i] > q.back()) {
                    q_s += 'R';
                    q.emplace_back(a[i]);
                }else{
                    break;
                }
            }
            if(p_s.length() > q_s.length()) {
                ans += p_s;
            }else{
                ans += q_s;
            }
            break;
        }
    }
    if(l == r && a[l] > c[k - 1]) {
        ans += 'L';
    }
    cout << ans.size() << endl;
    cout << ans << endl;
    return 0;
}
