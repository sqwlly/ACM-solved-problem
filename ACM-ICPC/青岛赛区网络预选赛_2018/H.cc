/*************************************************************************
    > File Name: H.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年10月02日 星期二 10时43分44秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
char s[100010];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int T;
	cin>>T;
	while(T--){
		scanf("%s",s);
		long long cnt = s[0]=='1'?1:2, d = cnt;
		for(int i = 1; s[i]; ++i){
			d += s[i] == s[i - 1] ? 2 * i : i;
			d += s[i] == '1' ? 1 : 2;
			cnt += d;
		}
		printf("%lld\n",cnt);
	}
    return 0;
}
