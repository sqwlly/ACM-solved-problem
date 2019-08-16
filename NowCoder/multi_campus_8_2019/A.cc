/*************************************************************************
    > File Name: A.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年08月10日 星期六 16时26分39秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
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
}
/****************************************************************************************************/
const int N = 1010,base = 1<<31, mod = 1e9+7;
int n,m,rectangle,a[N][N],Left[N][N],Right[N][N],h[N][N];
#define P pair<int,int>
int H[N][N],A[N],sum[N][N];
stack<int> st;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    string s;
    cin>>n>>m;
    for(int i = 1; i <= n; ++i){
		cin >> s;
        for(int j = 1; j <= m; ++j){
			a[i][j] = ((s[j - 1] == '1')? 1 : 0);
			if(a[i][j] == 1) H[i][j] = H[i - 1][j] + 1;
			else H[i][j] = 0;
        }
		for(int j = 1; j <= m; ++j) {
			sum[i][j] = sum[i][j - 1];
			if(s[j - 1] == '1') sum[i][j]++;
		}
    }
	int top = 0,ans = 0;
	for(int i = 1; i <= n; ++i) {
		top = 0;
		for(int j = 1; j <= m; ++j) {
			A[j] = H[i][j];
		}
		while(!st.empty()) st.pop();
		for(int j = 1; j <= m + 1; ++j) {
			if(st.empty() || A[j] >= A[st.top()]) {
				st.push(j);
			}else{
				while(!st.empty() && A[j] < A[st.top()]) {
					top = st.top();
					st.pop();
					if(st.empty()) {
						if(sum[i + 1][j - 1] != j - 1) ans++;
					}else{
						if(sum[i + 1][j - 1] - sum[i + 1][st.top()] != j - 1 - st.top()) {
						dbg(i,st.top(),j - 1, sum[i + 1][j - 1] - sum[i + 1][st.top()]);
							ans++;
						}
					}
				}
				st.push(j);
			}
		}
	}
	cout << ans << endl;
	return 0;
}
