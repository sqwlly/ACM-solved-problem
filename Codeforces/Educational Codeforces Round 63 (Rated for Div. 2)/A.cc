/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年04月22日 星期一 22时35分14秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
string s;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	cin >> s;
	int l = 0, r = 0;
	for(int i = 1; i < s.size(); ++i) {
		if(s[i] < s[i - 1]) {
			l = i - 1 + 1, r = i + 1;
			break;
		}
	}
	if(l != 0 ) {
		cout << "YES" << endl;
		cout << l << ' ' << r << endl;
	}else{
		cout << "NO" << endl;
	}
    return 0;
}
