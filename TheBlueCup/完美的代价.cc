/*************************************************************************
    > File Name: 完美的代价.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年11月13日 星期二 22时00分49秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n, ans = 0, cnt = 0, flag = 0;
	string s;
	cin>>n>>s;
	int t = n - 1;
	for(int i = 0; i < t; ++i) {
		 for(int j = t; j >= 0; --j) {
			if(i == j) {
				flag++;
				if(n % 2 == 0 || flag > 1) {
					puts("Impossible");
					return 0;
				}
				cnt = n / 2 - i;
				break;
			}else if(s[i] == s[j]) {
				for(int k = j; k < t; ++k) {
					s[k] = s[k + 1];
				}
				s[t] = s[i];
				ans += t - j;
				t--;
				break;
			}
		 }
	}
	cout<< ans + cnt <<endl;
    return 0;
}
