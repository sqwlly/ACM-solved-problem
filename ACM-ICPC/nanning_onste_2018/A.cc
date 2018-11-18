/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年09月16日 星期日 12时08分52秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	if(n == k) {
		puts("Adrien");
		return 0;
	}	
	if(n == k + 1) {
		puts("Austin");
		return 0;
	}
	if(n == 0) {
		puts("Austin");
	}else{
		if(k == 1){
			if(k & 1) {
				if(n & 1) {
					puts("Adrien");
				}else{
					puts("Austin");
				}
			}
		}else{
			puts("Adrien");
		}
	}
    return 0;
}
