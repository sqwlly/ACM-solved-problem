/*************************************************************************
    > File Name: B.cc
    > Author: sqwlly
    > Mail: sqw.lucky@gmail.com 
    > Created Time: 2019年05月17日 星期五 23时21分58秒
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


int main() {
#ifndef ONLINE_JUDGE
    freopen("input.in","r",stdin);
#endif
    ios::sync_with_stdio(false); cin.tie(0);
	int k;
	vector<char> v = {'a','e','i','o','u'};
	cin >> k;

	if(k < 25) {
		return cout << -1 << endl,0;
	}
	vector<vector<char>> alo;
	alo.push_back(v);
	do{
		bool ok = 1;
		for(int i = 0; i < v.size(); ++i) {
			for(int j = 0; j < alo.size(); ++j) {
				if(v[i] == alo[j][i]) {
					ok = 0;
					break;
				}
			}
			if(!ok) break;
			//cout << v[i] << ' ';
		}
		if(ok) {
			alo.push_back(v);
		}
	/*	for(int i = 0; i < v.size(); ++i) {
			cout << v[i] << ' ';
		}
		cout << endl;*/
		if(alo.size() == 5) break;

	}while(next_permutation(v.begin(),v.end()));
	string ans = "";
	int n = 0, m = 0;
	for(int i = 5; i * i <= k; ++i) {
		if(k % i == 0) {
			n = i, m = k / i;
			break;
		}
	}
	if(n == 0 || m == 0) {
		return cout << -1 << endl,0;
	}
	assert(n > 0);
	assert(m > 0);
	for(int i = 0; i < n; ++i) {
		/*int j = 0;
		while(j < n) {
			int t = 0;
			while(t < 5) {
				ans += alo[i % 5][t++];
				j++;
			}
		}*/
		for(int j = 0; j < m; ++j) {
			ans += alo[i % 5][j % 5];
		}
		/*for(int j = 0; j < 5 && i < 5; ++j) {
			ans += alo[i][j];
			//cout << alo[i][j] << ' ';
		}
		for(int t = 0; i >= 5 && t < 5; ++t) {
			ans += 'z';
		}
		for(int j = 0; j < m - 5; ++j) {
			ans += "z";
		}*/
		//cout << endl;
	}
	cout << ans << endl;
    return 0;
}
