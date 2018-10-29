/*************************************************************************
    > File Name: C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年10月29日 星期一 00时32分59秒
 ************************************************************************/

#include<bits/stdc++.h>
int bit[1010],flip[1010];
void F(int d)
{
	for(int i = 1, j = d; i <= d/2; ++i,--j){
		int t = bit[i];
		bit[i] = bit[j];
		bit[j] = t;
	}
}
using namespace std;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	string s;
	cin>>s; // bbaababab
	// bbab  abaa  aaba  bbabab       abbbab ababba
	int len = s.length();
	for(int i = 1; i <= len; ++i) {
		if(s[i-1] == 'a') bit[i] = 1;
		else bit[i] = 0;
	}
	for(int i = 1; i <= len; ++i){
		if(bit[1] == 1) {
			int d;
			
			for(d = 2; d <= len; ++d){
				if(bit[d] == 0) break;
			}
			for(int j = d; j <= len; ++j){
				if(bit[j] == 1) {
					flip[j-1] = 1;
					F(j-1);
					break;
				}
			}
		}else{
			int d;
			for(d = 2; d <= len; ++d){
				if(bit[d] == 1) break;
			}
			for(int j = d; j <= len; ++j){
				if(bit[j] == 0) {
					flip[j-1] = 1;
					F(j-1);
					break;
				}
			}
		}
	}
/*	for(int i = 1; i <= len; ++i){
		char ch = bit[i]?'a':'b';
		printf("%c",ch);
	}*/
	if(bit[len] == 1) flip[len] = 1;
	// aaabbba
	// bbaabbabab  aabbbbabab bbbaabab  aabbbbab bbbbaaab aaabbbbb
	for(int i = 1; i <= len; ++i){
		printf("%d%c",flip[i],i==len?'\n':' ');
	}
    return 0;
}
