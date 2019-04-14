/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年04月13日 星期六 19时01分11秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 1E6;
string s;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		cin >> s;
		int len = s.length();
		int ok = 1;
		for(int i = 0; i < len;) {
			if(s.substr(i,4) == "2050") {
				i += 4;
			}else{
				ok = 0;
				break;
			}
		}
		if(ok) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
    return 0;
}
