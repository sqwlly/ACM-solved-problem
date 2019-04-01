/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月31日 星期日 22时04分41秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;

bool check(char a,char b)
{
	if(abs(a - b) == 1) return 1;
	return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	string s;
	for(int i = 0; i < n; ++i) {
		cin >> s;
		bool vis[250] = {0};
		bool ok = 1;
		sort(s.begin(), s.end());
		vis[s[0]] = 1;
	//	cout << s << endl;
		for(int j = 1; j < s.length(); ++j) {
			if(vis[s[j]] || check(s[j], s[j - 1]) == 0) {
			//	cout << s[j] << s[j - 1] << endl;
			//	DEBUG(vis[s[j]]);
			//	cout << abs(s[j] - s[j - 1]) << endl;
				ok = 0;
			}else{
				vis[s[j]] = 1;
			}
		}
		if(ok) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
    return 0;
}
