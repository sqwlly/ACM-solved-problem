#include<bits/stdc++.h>
using namespace std;
const int N = 1E4;
int m[N],phi[N],p[N],nump;


int main()
{
    phi[1] = 1;
    for(int i = 2; i < N; ++i) {
        if(!m[i]) {
            p[++nump] = i;
            phi[i] = i - 1;
        }
        for(int j = 1; j <= nump && p[j] * i < N; ++j) {
            m[p[j] * i] = 1;
            if(i % p[j] == 0) {
                phi[p[j] * i] = phi[i] * p[j];
                break;
            }else{
                phi[p[j] * i] = phi[i] * (p[j] - 1);
            }
        }
    }
    cout << phi[2020] << ' ' << phi[6] << endl;
    return 0;
}