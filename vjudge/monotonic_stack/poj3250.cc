/*************************************************************************
    > File Name: poj3250.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年07月31日 星期三 11时05分25秒
 ************************************************************************/

#include<iostream>
#include<stack>
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
const int N = 8E4+10;
stack<int> st;
int a[N];
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,x;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	//10 3 7 4 12 2
	long long sum = 0;
	a[n] = 1E9;
	for(int i = 0; i <= n; ++i) {
		if(st.empty() || a[st.top()] > a[i]) {
			st.push(i);
		}else{
			while(!st.empty() && a[st.top()] <= a[i]) {
				sum += i - st.top() - 1;
				st.pop();
			}
			st.push(i);
		}
	}
	cout << sum << endl;
    return 0;
}
