/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com
    > Created Time: 2019年01月21日 星期一 13时58分28秒
 ************************************************************************/

#include<bits/stdc++.h>
typedef long long LL;
using namespace std;
int a[7000], max1[7000], max2[7000];

LL union1(int a,int b)
{
    LL num = 0;
   // int t1 = 0, t2 = 0;
    string t1 = "", t2 = "";
    while(a)
    {
        t1 += a % 10 + '0';
     //   t1 = t1 * 10 + a % 10;
        a /= 10;
    }
    while(b)
    {
        t2 += b % 10 + '0';
       // t2 = t2 * 10 + b % 10;
        b /= 10;
    }
    reverse(t1.begin(),t1.end());
    reverse(t2.begin(),t2.end());
    int k1 = 0, k2 = 0;
    while(k1 < t1.size())
    {
        num = num * 10 + t1[k1] - '0';
        k1++;
    }
    while(k2 < t2.size())
    {
        num = num * 10 + t2[k2] - '0';
        k2++;
    }
    return num;
}

int main() {
#ifndef ONLINE_JUDGE
//    freopen("input.in", "r", stdin);
#endif
    int T, n, t = 0;
    cin >> T;
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &a[i]);
        }
        memset(max1,0,sizeof max1);
        max1[1] = a[1];
        for(int i = 2; i <= n; ++i) {
            max1[i] = max(max1[i - 1],a[i]);
        }
        long long ans = 0;
        for(int i = 2; i <= n; ++i) {
            ans = max(ans, union1(max1[i - 1], a[i]));
        }
        cout << "Case #"<<(++t)<<": "<<ans << endl;
    }
    return 0;
}

