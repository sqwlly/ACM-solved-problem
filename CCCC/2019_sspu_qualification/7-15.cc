/*************************************************************************
    > File Name: 7-15.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月13日 星期三 21时55分17秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	if(n % 2 == 0) {
		if(n != 2) {
			cout << "Marry" << endl;
		}else{
			cout << "Tom" << endl;
		}
	}else{
		if(n != 1) {
			cout << "Tom" << endl;
		}else{
			cout << "Marry" << endl;
		}
	}
    return 0;
}
