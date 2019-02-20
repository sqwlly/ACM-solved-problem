/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年01月22日 星期二 22时43分43秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;
vector<char> v;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	string s;
	cin >> s;
	int len = s.length();
	int cnt = 0;
	v.push_back(s[0]);
	int k = 1;
	for(int i = 1; i < len; ++i) {
		if(s[i] == v[k - 1]) {
			cnt++;
			v.pop_back();
			k--;
		}else{
			v.push_back(s[i]); //a
			k++;
		}
	}
//	for(int i = 0; i < k; ++i) {
//		putchar(v[i]);
//	}
	//cout<<k<<endl; abbaa
	while(k > 1) {
		if(v[k - 1] == v[k - 2]) {
			k -= 2;
			cnt++;
		}else{
			//cout << k << endl;
			k--;
		}

	}
	//cout<<k<<endl;
	puts((cnt & 1) ? "Yes" : "No");
    return 0;
}
