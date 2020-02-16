/*************************************************************************
  > File Name: C.cc
  > Author: sqwlly
  > Mail: sqw.lucky@gmail.com 
  > Created Time: 2020年01月14日 星期二 12时11分07秒
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
typedef long long LL;
bool check(LL n)
{
	for(LL i = 2; i * i <= n; ++i) {
		if(n % i == 0) {
			return 0;
		}
	}
	return 1;
}

void solve(LL n)
{
	if(check(n)) {
		cout << n << '\n';
		return;
	}
	vector<int> v;
	LL t = n;
	for(LL i = 2; i * i <= t; ++i) {
		if(t % i == 0) {
			v.push_back(i);
			while(t % i == 0) t /= i;
		}
	}
	if(t > 1) v.push_back(t);
	if(v.size() >= 2) {
		cout << 1 << '\n';
	}else{
		cout << v[0] << '\n';
	}
	//1 3
	//2 4
	//
	//2 3 6
	//1 3
	//2 4
	//3 5
	//4 6
	//1 4
	//2 5
	//3 6
	//n - d_i
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.in","r",stdin);
#endif
	ios::sync_with_stdio(false); cin.tie(0);
	LL n = 0;
	cin >> n;
	solve(n);
	return 0;
}
