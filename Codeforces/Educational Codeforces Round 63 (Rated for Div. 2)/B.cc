/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年04月22日 星期一 22时44分10秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 1E5+10;
int sum[N];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	n = s.size();
	//cout << n << endl;
	int res = n - 11, cnt = 0, k = res / 2;
	for(int i = 0; i <= n - 11; ++i) {
		if(s[i] == '8') {
			cnt++;
			sum[i + 1] = sum[i] + 1;		
		}else{
			sum[i + 1] = sum[i];
		}
	}
	if(cnt > res / 2) {
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
    return 0;
}
