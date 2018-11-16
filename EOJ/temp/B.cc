/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年11月16日 星期五 19时35分56秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
const int N = 1E5+100;
char s[N],b[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	scanf("%s%s",s,b);
	int len = strlen(s), len1 = strlen(b);
	if(len < 2) {
		printf("%c",max(s[0],b[0])-1);
		return 0;
	}
	if(strcmp(s,b) > 0) {
		for(int i = len - 1; i >= 0; --i) {
			
				if(s[i] - 1 < 'A') {
					for(int j = i; j >= 0; --j) {
						if(s[j] - 1 < 'A') {
							s[j] = 'Z';
						}else{
							s[j]--;
							break;
						}
					}
					break;
				}else{
					s[i]--;
					break;
				}
			
		}
		printf("%s",s);
	}else{
		for(int i = len - 1; i >= 0; --i) {
			
				if(b[i] - 1 < 'A') {
					for(int j = i; j >= 0; --j) {
						if(b[j] - 1 < 'A') {
							b[j] = 'Z';
						}else{
							b[j]--;
							break;
						}
					}
					break;
				}else{
					b[i]--;
					break;
				}
			
		}
		printf("%s",b);
	}
    return 0;
}
