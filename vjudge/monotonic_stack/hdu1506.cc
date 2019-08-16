/*************************************************************************
    > File Name: hdu1506.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年07月31日 星期三 15时48分36秒
 ************************************************************************/

#include<iostream>
#include<stack>
#include<vector>
using namespace std;
/*
#ifndef ONLINE_JUDGE
#define dbg(args...)                                   \
    do{                                                \
	        cout << "\033[32;1m" << #args << " -> ";   \
         err(args);                                    \
      } while(0)                                       
#else
#define dbg(...)
#endif
void err()
{
    cout << "\033[39;0m" << endl;
}
template <template <typename...> class T, typename t, typename... Args>
void err(T<t> a, Args... args)
{
    for (auto x : a) cout << x << ' ';
    err(args...);
}
template <typename T, typename... Args>
void err(T a, Args... args)
{
    cout << a << ' ';
    err(args...);
}*/
/****************************************************************************************************/

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n;
	while(cin >> n && n) {
		vector<long long> v;
		long long x;
		long long ans = 0;
		for(int i = 0; i < n; ++i) {
			cin >> x; v.push_back(x);
		}
		v.push_back(-1);
		stack<int> st;
		for(int i = 0; i <= n; ++i) {
			if(st.empty() || v[st.top()] <= v[i]) {
				st.push(i);
			}else{
				while(!st.empty() && v[st.top()] > v[i]) {
					int j = st.top(); st.pop();
					int t = (st.empty() ? i : i - st.top() - 1);
				//	dbg(i,j);
					ans = max(ans, 1LL * v[j] * t);
				}
				st.push(i);
			}
		}
		cout << ans << endl;
	}
    return 0;
}

