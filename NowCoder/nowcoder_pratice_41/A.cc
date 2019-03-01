/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月01日 星期五 19时08分04秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
//1 1 1 1 1
//0 0 0 1 1
//0 1 1 1 1
//
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,m;
	int T;
	cin >> T;
	while(T--) {
		cin >> n >> m;
		cout << ((n == m)? "Yes" : "No")<< endl;	
	}
	return 0;
}
