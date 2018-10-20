/*************************************************************************
    > File Name: K.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年10月20日 星期六 16时34分35秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
int a[100100];
int main()
{
#ifndef ONLINE_JUDGE
#endif
	int n,k;
	long long sum = 0;
	scanf("%d%d",&n,&k);
	for(int i = 0; i < n; ++i){
		scanf("%d",&a[i]);
		sum += a[i];
	}
	if(sum % k != 0) {
		puts("No");
		return 0;
	}
	vector<int> ans;
	long long tmp = 0,ret = sum / k;
	int cnt = 0;
	for(int i = 0; i < n; ++i){
		tmp += a[i];
		cnt++;
		if(tmp == ret) {
			ans.push_back(cnt);
			cnt = 0;
			tmp = 0;
		}else if(tmp > ret){
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	for(int i = 0; i < ans.size(); ++i)
		printf("%d%c",ans[i],i==ans.size()-1?'\n':' ');
    return 0;
}
