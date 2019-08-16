/*************************************************************************
    > File Name: bzoj1113_.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年07月31日 星期三 15时24分58秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
/*#ifndef ONLINE_JUDGE
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
const int N = 3E5;
int a[N];
stack<int> st;
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n, w, h;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> w >> a[i];
	}
	int ans = 0;
	for(int i = 0; i <= n; ++i) {
		if(st.empty() || a[st.top()] <= a[i]) st.push(i);
		else {
			while(!st.empty() && a[st.top()] >= a[i]) {
				if(a[st.top()] != a[i]) ans++;
				st.pop();
			}
		//	if(!st.empty()) ans++;
			st.push(i);

		}
	}
	cout << ans << endl;
    return 0;
}
