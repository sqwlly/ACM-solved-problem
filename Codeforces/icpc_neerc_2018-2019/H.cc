/*************************************************************************
    > File Name: H.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年10月20日 星期六 17时10分44秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
string str[10010];
int len[10010];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n;
	ios::sync_with_stdio(false);
	cin>>n;
	for(int i = 0; i < n; ++i){
		cin>>str[i];
		len[i] = str[i].length();
//		cout<<len[i]<<endl;
	}
//	cout<<"---------"<<endl;
	int q;
	cin>>q;
	string s;
	while(q--){
		cin>>s;
		int f = 0, cnt = 0;
		string ret;
		for(int i = 0; i < n; ++i){
			f = str[i].find(s);
			if(f < str[i].length()){
				cnt++;
				ret = str[i];
			}
//			cout<<str[i].length()<<endl;
		}
		cout<<cnt<<' ';
		if(cnt == 0) {
			cout<<"-"<<endl;
		}else{
			cout<<ret<<endl;
		}
	}
    return 0;
}
