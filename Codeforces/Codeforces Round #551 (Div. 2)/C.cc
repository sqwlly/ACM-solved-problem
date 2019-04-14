/*************************************************************************
    > File Name: C.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年04月13日 星期六 23时01分34秒
 ************************************************************************/

#include<bits/stdc++.h>

#define DEBUG(x) std::cerr << #x << '=' << x << std::endl

using namespace std;
const int N = 3E5+10;
int q[N],rgt[N];
stack<char> st;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n;
	string s;
	cin >> n >> s;
	for(int i = n - 1; i >= 0; --i) {
		if(s[i] == '?') {
			q[i] = q[i + 1] + 1;
		}else{
			q[i] = q[i + 1];
		}
		if(s[i] == ')') {
			rgt[i] = rgt[i + 1] + 1;
		}else{
			rgt[i] = rgt[i + 1];
		}
	}
	int flag = 0, cnt = 0, ok = 1, r = 0, l = 0;
	if(s[0] == ')' || s[n - 1] == '(') return cout << ":(" << endl,0;
	if(s[0] == '?') s[0] = '(';
	if(s[n - 1] == '?') s[n - 1] = ')';

	for(int i = 1; i < n - 1; ++i) {
		if(s[i] == '?') {
			if(cnt < rgt[n - i - 1]) {
				cnt++;
				s[i] = '(';
			}else{
				s[i] = ')';
				r++;
			}
//			if(q[n - i - 1] < cnt) { //(()())
//				ok = 0;
//			}
		}/*else if(s[i] == '(') {
			cnt++;
		}else if(s[i] == ')') { // (((())))
			r++;
			if(r >= cnt) {
				ok = 0;
			}
		}*/
	}
	int L = 0, R = 0;
	for(int i = 0; i < n; ++i) {
		if(s[i] == '(') {
			st.push('(');
		}else{
			if(!st.empty()) //((())
				st.pop();
			else
				ok = 0;
			if(st.size() == 0 && i < n - 1) ok = 0;
		}
	}
//	DEBUG(st.size());
	if(ok == 0 || !st.empty()) cout << ":(" << endl;
	else{
		cout << s << endl;
	}
    return 0;
}
