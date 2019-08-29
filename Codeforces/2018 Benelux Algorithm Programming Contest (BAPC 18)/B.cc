/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年08月28日 星期三 11时57分39秒
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

struct node{
	string name;
	int m,d;
	bool operator < (const node &u)const{
		if(u.m == m) return u.d > d;
		return u.m > m;
	}
}a[102];
int day[12] = {};
int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    //ios::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	string name;

	for(int i = 0; i < n; ++i) {
		cin >> a[i].name;
		scanf("%2d-%2d",&a[i].m,&a[i].d);
	}
	sort(a, a + n);
	for(int i = 0; i < n; ++i) {
		printf("%02d-%02d\n",a[i].m,a[i].d);
	}
	int day = 0;
	for(int i = 1; i < n; ++i) {
		day = a[i].m
	}
    return 0;
}
