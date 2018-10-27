/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年10月25日 星期四 22时34分15秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
int n;
bool ok(string s)
{
	int ret = 0;
	int cnt[200] = {0};
	for(int i = 0; i < s.length(); ++i){
		cnt[s[i]]++;
	}
	for(int i = 0; i < 200; ++i){
		if(cnt[i] > s.length()/2) return 0;
	}
	return 1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	cin>>n;
	string s;
	cin>>s;
	string ans = "";
	for(int i = 0; i < s.length(); ++i){
		string t = "";
		for(int j = i; j < s.length(); ++j){
			t += s[j];
			if(ok(t)){
				ans = t;
			}
		}
	}
	if(ans == "")
	{
		puts("NO");
	}else{
		puts("YES");
		cout<<ans<<endl;
	}
    return 0;
}
