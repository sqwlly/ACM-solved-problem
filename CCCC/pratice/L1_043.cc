/*************************************************************************
    > File Name: L1_043.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年03月03日 星期日 10时30分21秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 1001;
//13 : 16 - 8 : 35 = 4 * 60 + 41 + 60 + 50 = 391 / 2 = 196

vector<string> book[N];

int toint(string s)
{
	int a = ((s[0] - '0') * 10 + s[1] - '0') * 60 + (s[3] - '0') * 10 + s[4] - '0';
	return a;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,id;
	cin >> n;
	string s;
	char c;
	int cnt = 0, sum = 0;
	for(int i = 0; i < n; ) {
		cin >> id >> c >> s;
		if(id == 0) {
			if(cnt == 0) cout << "0 0" << endl;
			else cout << cnt << ' ' << (int)(1.0 * sum / cnt + 0.5) << endl;
			++i;
			sum = cnt = 0;
			for(auto &it : book) it.clear();
			continue;
		}
		if(c == 'S') {
			if(book[id].size() == 1) book[id].pop_back();
			book[id].push_back(s);
		}
		if(c == 'E' && book[id].size() == 1) {
			int b = toint(s);
			int a = toint(book[id][0]);
			book[id].pop_back();
			sum += b - a;
			cnt++;
		}
	}
    return 0;
}
