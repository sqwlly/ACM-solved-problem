/*************************************************************************
    > File Name: D1.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2018年12月22日 星期六 12时12分47秒
 ************************************************************************/

#include<bits/stdc++.h>

using namespace std;

stack< int > st;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
	int n,x;
	cin >> n >> x;
	st.push(x);
	for(int i = 1; i < n; ++i) {
		cin >> x;
		if(!st.empty() && (st.top() - x)% 2 == 0) {
			st.pop();
		}else{
			st.push(x);
		}
	}
	puts(st.size() > 1 ? "NO" : "YES");
    return 0;
}
