/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年05月14日 星期二 22时41分22秒
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
int a[200100];
map<int,int> m;
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		m[a[i]]++;
		//s.insert(a[i]);
	}
	sort(a, a + n);
	int ans = 0, day = 1;
	for(int i = 0; i < n; ++i) {
		if(a[i] >= day) {
			day++;
		}
//		if(a[i] < day) continue;
//		day++;
//		dbg(i,a[i],day);
	}
	cout << day - 1 << endl;
	return 0;/*
	int day = 0;
	for(auto i : m) {
		while(i.first < day) {
			i.
		}
		day++;
		if(i.first < day) {
			cout << day - 1 << endl;
			return 0;
		}
	}
	cout << m.size() << endl;
    return 0;*/
}
