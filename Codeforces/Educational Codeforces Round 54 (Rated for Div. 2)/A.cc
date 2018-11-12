/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年11月12日 星期一 22时32分26秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n;
	string s;
	cin>>n>>s;
	string t = "";
	for(int i = 0; i < s.length(); ++i){
		if(i == 0 && s[0] > s[1]) {
			t = s.substr(1,s.length());
			break;
		}
		if(i == n - 1) {
			t = s.substr(0,s.length() - 1);
			break;
		}
		if(s[i] > s[i + 1]) {
			t = s.substr(0,i) + s.substr(i + 1,s.length());
			break;
		}
	}
	cout<< t <<endl;

    return 0;
}
