/*************************************************************************
    > File Name: H.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年10月20日 星期六 17时10分44秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
map<string,int> vis, cnt;
map<string,string> str;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n;
	ios::sync_with_stdio(false);
	cin>>n;
	string s;
	for(int i = 0; i < n; ++i){
		cin>>s;
		vis.clear();
		string ret;
		for(int i = 0; i < s.length(); ++i){
			ret = "";
			for(int j = i; j < s.length(); ++j){
				ret += s[j];
				if(vis[ret] == 0) {
					vis[ret] = 1;
					cnt[ret]++;
					str[ret] = s;
			//		cout<<ret<<endl;
				}
			}
		}
	}
	int q;
	cin>>q;
	string ans;
	while(q--){
		cin>>ans;
		if(cnt[ans] == 0) {
			cout<<"0 -"<<endl;
		}else{
			cout<<cnt[ans]<<' '<<str[ans]<<endl;;
		}
	}
    return 0;
}
