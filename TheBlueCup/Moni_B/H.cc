/*************************************************************************
    > File Name: H.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com
    > Created Time: 2019年01月31日 星期四 15时10分39秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
int a[500100];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    int n;
    cin >> n;
    for(int i = 0; i < n; ++i) {
        scanf("%d",a+i);
       // a[i] = -a[i];
    }
    sort(a,a+n);
    int cnt = n, j = n / 2;
	for(int i = 0; i < n / 2; ++i) {
		for(; j < n; ++j) {
			if(a[i] * 2 <= a[j]) {
				cnt--;
                j++;
				break;
			}
		}
        if(j == n) break;
	}
    cout << cnt << endl;
    return 0;
}

