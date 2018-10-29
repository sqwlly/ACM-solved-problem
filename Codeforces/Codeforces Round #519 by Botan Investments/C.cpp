/*************************************************************************
    > File Name: C.cpp
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年10月29日 星期一 11时09分41秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	string s;
	cin>>s;
	bool flip[1010] = {0};
	for(int i = 0; i < s.length() - 1; ++i){
		if(s[i] != s[i + 1]) {
		//	cout<<i<<' '<<s[i]<<endl;
			flip[i] = 1;
		}
	}
	if(s[s.length()-1] == 'a') flip[s.length() - 1] = 1;
	for(int i = 0; i < s.length(); ++i){
		printf("%d%c",flip[i],i==s.length()-1?'\n':' ');
	}
    return 0;
}
