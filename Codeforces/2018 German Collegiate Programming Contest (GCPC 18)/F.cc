/*************************************************************************
    > File Name: F.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年08月26日 星期一 11时24分50秒
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

// 5 8  3     8 - 5 - (8 - 5) - ((8 - 5))
// 5 3  2  
// 2 3  1
// 2 1  1
// 1 1  0
// 1 0  
const int N = 1E5+10;
bool ok;
void dfs(int a,int b,int k)
{
	if((a <= 0 && b == 1) || (a == 1 && b <= 0)) {
		ok = 1;
		return;
	}
	if(a <= 0 || b <= 0) return;
	if(k)
		dfs(a, b - a, k ^ 1);
	else
		dfs(a - b, b, k ^ 1);
}

pair<int,int> a[N];

//a, b
//a, b - a																								                             a - b ,
//a - (b - a), b - a															a - b + a, b - a                                    2a - b , b - a
//a - (b - a), b - a - (a - (b - a))											a - b + a, b - a - a + b - a                        2a - b , 2b - 3a
//a - (b - a) - (b - a - (a - (b - a))), b - a - (a - (b - a))					a - b + a - b + a + a - b + a, b - a - a + b - a	5a - 3b, 2b - 3a


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int n,f[51] = {0,1,2},k = 2;
	for(int i = 3; i <= 50; ++i) {
		f[i] = f[i - 1] + f[i - 2];
		k++;
		if(f[i] > 1e5) break; 
	}
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> a[i].first;
		a[i].second = i;
	}
	sort(a + 1, a + 1 + n);
	if(a[1].first == a[2].first && a[1].first == 1) {
		return cout << a[1].second << ' ' << a[2].second << endl,0;
	}
	int x,y;
	vector<pair<int,int>> v;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= k; ++j) {
			if(a[i].first == f[j]) {
		//		dbg(i);
				v.push_back(make_pair(a[i].second,j));
				break;
			}
		}
	}
	for(int i = 1; i < v.size(); ++i) {
		if(v[i - 1].second + 1 == v[i].second) {
			return cout << v[i - 1].first << ' ' << v[i].first << endl,0;
		}
	}
	cout << "impossible" << endl;
	/*
	n = 100000;
	for(int i = 1; i <= n; ++i) {
		for(int j = i + 1; j <= n; ++j) {
			ok = 0;
			dfs(i,j,1);
			if(ok) cout << i << ' ' << j << endl;
		}
	}
	*/
    return 0;
}
